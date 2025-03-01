class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int len = nums.size();

        for (int i = 1 ; i < len ; i++){
            if (nums[i-1] == nums[i] && nums[i] != 0) {
                nums[i-1] = nums[i-1] * 2;
                nums[i] = 0;
            }
        }

        // 1 0 2 0 0 1

        int i = 0;
        for (int j = 0 ; j < len ; j++){
            if (nums[j]) {
                swap(nums[j],nums[i]);
                i++;
            }
        }

        return nums;
        
    }
};