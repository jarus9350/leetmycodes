class MovieRentingSystem {
public:
    struct Compare {
        bool operator() (const pair<int,int>& a, const pair<int,int>& b) const{
            if (a.second == b.second) {
                return a.first < b.first;
            }

            return a.second < b.second;
        }
    };

    struct Comp{
        bool operator() (const vector<int>& a, const vector<int>& b) const{
            if (a[0] == b[0]) {
                if (a[1] == b[1]) {
                    return a[2] < b[2];
                }
                return a[1] < b[1];
            }

            return a[0] < b[0];
        }
    };

    unordered_map<int,set<pair<int,int>, Compare>> movieShopPrice;
    set<vector<int>, Comp>  priceShopMovieALL;
    set<vector<int>, Comp>  priceShopMovieRented;
    map<pair<int,int>,int> shopMoviePrice;

    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for (auto e: entries){
            auto shop = e[0];
            auto movie = e[1];
            auto price = e[2];

            movieShopPrice[movie].insert({shop,price});
            priceShopMovieALL.insert({price,shop,movie});
            shopMoviePrice[{shop,movie}] = price;
        }
    }
    
    vector<int> search(int movie) {
        auto& shopsPrice = movieShopPrice[movie];
        if (shopsPrice.size() == 0) return {};

        vector<int> ans;
        auto it = shopsPrice.begin();
        for (int i = 0 ; i < 5 && i < shopsPrice.size(); i++){
            ans.push_back(it->first);
            it++;
        }

        // auto it2 = priceShopMovieALL.begin();
        // for (int i = 0 ; i < 5 && it2 != priceShopMovieALL.end() ;) {
        //     auto price = (*it2)[0];
        //     auto shop = (*it2)[1];
        //     auto m = (*it2)[2];
            
        //     if (m == movie) {
        //         ans.push_back(shop);
        //         i++;
        //     }

        //     it2++;

        // }

        return ans;
    }
    
    void rent(int shop, int movie) {
        // auto price = moviePrice[movie];
        auto price = shopMoviePrice[{shop,movie}];
        movieShopPrice[movie].erase({shop,price});
        priceShopMovieALL.erase({price,shop,movie});
        priceShopMovieRented.insert({price,shop,movie});
    }
    
    void drop(int shop, int movie) {
        auto price = shopMoviePrice[{shop,movie}];
        movieShopPrice[movie].insert({shop,price});
        priceShopMovieRented.erase({price,shop,movie});
        priceShopMovieALL.insert({price,shop,movie});
    }
    
    vector<vector<int>> report() {
        vector<vector<int>> ans;
        auto it = priceShopMovieRented.begin();
        for(int i = 0 ; i < 5 && i < priceShopMovieRented.size(); i++){
            auto price = (*it)[0];
            auto shop = (*it)[1];
            auto movie = (*it)[2];

            ans.push_back({shop,movie});
            it++;
        }
        return ans;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */