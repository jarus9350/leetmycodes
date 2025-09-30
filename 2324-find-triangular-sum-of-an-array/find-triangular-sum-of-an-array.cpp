class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int i = 0, j = nums.size() - 1;
        while ( j > 0) {
            for ( i = 0 ; i < j ; i++ ){
                nums[i] = (nums[i] + nums[i+1]) % 10;
            }
            j--;
        }

        return nums[0];

    }
};