class Solution {
public:
    int partition(vector<int>& nums, int l ,int r){
        int pivot = nums[r];
        int i = l;
        for (int j = l ; j < r ; j++){
            if (nums[j] < pivot){
                swap(nums[j],nums[i]);
                i++;
            }
        }

        swap(nums[r],nums[i]);
        return i;
    }

    void quickSelect(vector<int>& nums,int l,int r,int idx){
        if (l < r){
            int i = partition(nums,l,r);
            if (i < idx){
                quickSelect(nums,i+1,r,idx);
            } else if ( i > idx){
                quickSelect(nums,l,i-1,idx);
            } else if (i == idx){
                return;
            }
        }
    }


    int findKthLargest(vector<int>& nums, int k) {
        int idx = nums.size() - k;
        quickSelect(nums,0,nums.size()-1,idx);
        return nums[idx];        
    }
};