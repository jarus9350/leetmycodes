class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        // unordered_map<int,int> mp;
        unordered_set<int> s;

        for (auto n: arr){
            if (s.find(n) != s.end()){
                return true;
            }

            s.insert(n*2);
            if (n % 2 == 0) s.insert(n/2);
        }

        return false;
        
    }
};