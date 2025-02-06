class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        map<int,set<pair<int,int>>> mp;

        for (int i = 0 ; i < nums.size(); i++){
            for (int j = i+1; j < nums.size() ; j++){
                if (i != j) {
                    int a = nums[i];
                    int b = nums[j];
                    mp[a*b].insert({min(a,b),max(a,b)});
                }
            }
        }

        int ans = 0;
        for (auto [key, val] : mp){
            int number = val.size();
            if (number > 1) {
                ans += number*(number - 1) *4;
            }
        }

        return ans;

        
    }
};