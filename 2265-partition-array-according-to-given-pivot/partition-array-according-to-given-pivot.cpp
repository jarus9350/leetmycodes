class Solution {
public:
    //
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int> ans(n,0);

        int i = 0;
        int j = n - 1;

        for (int k = 0 ; k < n ; k++) {
            if (nums[k] < pivot) {
                ans[i++] = nums[k];
            }
        }

        for (int k = n - 1 ; k >= 0 ; k--) {
            if (nums[k] > pivot) {
                ans[j--] = nums[k];
            }
        }

       for (int k = i ; k <= j ; k++) ans[k] = pivot;

       return ans;
        
    }
};