class Solution {
public:
    int pivot(vector<int>& nums,int l,int r){
        int pivot = nums[r];
        int p = l;

        for (int j = l ; j < r ; j++){
            if (nums[j] < pivot) {
                swap(nums[p],nums[j]);
                p++;
            }
        }

        swap(nums[p],nums[r]);
        return p;
    }

    void quickSelect(vector<int>& nums,int l,int r,int idx){
        if (l < r){
            int p = pivot(nums,l,r);

            if ( idx > p) {
                quickSelect(nums,p+1,r,idx);
            } else if ( idx < p ) {
                quickSelect(nums,l,p-1,idx);
            } else if ( idx == p ) {
                return;
            }
        }
    }

    int findKthLargest(vector<int>& nums, int k) {
        int idx = nums.size() - k;
        int l = 0;
        int r = nums.size() - 1;
        quickSelect(nums,l,r,idx);
        return nums[idx];
    }
};