class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        unordered_map<int,int> mp;
        for (auto n : nums){
            mp[ (( n % value ) + value ) % value]++;
        }

        for (int MEX = 0; MEX <= nums.size(); MEX++){
            int mMEX = MEX % value;
            if (mp.find(mMEX) != mp.end()) {
                if (mp[mMEX] == 0) return MEX;
                mp[mMEX]--;
            } else {
                return MEX;
            }
        }

        return 0;
    }
};