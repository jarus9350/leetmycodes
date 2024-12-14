class Solution {
public:
    // long long countSubsequences(int len){
    //     return ((len)*(len+1))/2;
    // }

    long long continuousSubarrays(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int j = 0;

        map<int,int> mp; // window

        long long ans = 0;

        while (j < n){
            
            mp[nums[j]]++;

            if (mp.rbegin()->first - mp.begin()->first <= 2 ){
                ans += j - i + 1;
            } else {
                // reduce window
                while (mp.rbegin()->first - mp.begin()->first > 2 ) {
                    mp[nums[i]]--;
                    if (mp[nums[i]] == 0){
                        mp.erase(nums[i]);
                    }
                    i++;
                }

                ans += j - i + 1;
            }

            j++;

        }

        return ans;

    }
};