class FoodRatings {
public:
    struct Compare {
        bool operator()(const pair<int,string>& a, const pair<int,string>& b) const{
            if (a.first == b.first) return a.second < b.second;
            return a.first > b.first;

            // if (a.first != b.first) return a.first > b.first;
            // return a.second < b.second;
        }
    };
    

    unordered_map<string,string> foodCuisine;
    unordered_map<string,pair<int,string>> fC;
    unordered_map<string,int> foodRating;
    unordered_map<string,set<pair<int,string>, Compare> > cuisineFood;
    
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for (int i = 0 ; i < foods.size() ; i++){
            auto& food = foods[i];
            auto& cuisine = cuisines[i];
            auto& rating  = ratings[i];

            foodCuisine[food] = cuisine;
            foodRating[food] = rating;
            cuisineFood[cuisine].insert({rating,food});
        }
    }
    
    void changeRating(string food, int newRating) {
        auto& oldRating = foodRating[food];
        auto& cuisine = foodCuisine[food];

        auto& s = cuisineFood[cuisine];

        s.erase(make_pair(oldRating,food));
        s.insert({newRating,food});

        foodRating[food] = newRating;
    }
    
    string highestRated(string cuisine) {
        auto it = cuisineFood[cuisine].begin();
        return (it->second);
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */