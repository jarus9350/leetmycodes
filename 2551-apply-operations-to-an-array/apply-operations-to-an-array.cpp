class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int len = nums.size();
        int operations = len - 1;

        for (int i = 1 ; i < len ; i++){
            if (nums[i-1] == nums[i] && nums[i] != 0) {
                nums[i-1] = nums[i-1] * 2;
                nums[i] = 0;
            }
        }

        vector<int> ans(len,0);

        int i = 0;
        for (auto n: nums){
            if (n) {
                ans[i++] = n;
            }
        }

        return ans;
        
    }
};