class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_map<int,int> mp;

        for (auto n: arr){
            if (mp.find(n) != mp.end()){
                return true;
            }

            mp[n*2]++;
            if (n % 2 == 0) mp[n/2]++;
        }

        return false;
        
    }
};