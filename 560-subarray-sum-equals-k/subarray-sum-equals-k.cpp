class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        mp[0]++;

        int sum = 0;
        int ans = 0;
        for (auto n: nums){
            sum += n;

            int remaining = sum - k;
            if (mp.find(remaining) != mp.end()) {
                ans += mp[remaining];
            }

            mp[sum]++;
        }

        return ans;


        
    }
};