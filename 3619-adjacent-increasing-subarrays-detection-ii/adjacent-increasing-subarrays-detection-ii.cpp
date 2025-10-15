class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int prev = 0;
        int curr = 1;

        int ans = 1;

        for (int i = 1; i < nums.size() ; i++){
            if (nums[i] > nums[i-1]) {
                curr++;
                
                ans = max(ans, curr/2);
                ans = max(ans, min(curr,prev));

            } else {
                prev = curr;
                curr = 1;


            }
        }

        return ans;
    }
};