class Solution {
public:
    int binarySearch(vector<int>& nums,int l,int h,int target) {
        while (l <= h) {
            int m = l + (h-l)/2;

            if (nums[m] == target) {
                return m;
            } else if (nums[m] < target) {
                l = m + 1;
            } else if (nums[m] > target) {
                h = m - 1;
            }
        }

        return -1;
    }


    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0;
        int h = n - 1;
         
        int pivot = -1;

        while (l <= h) {
            int m = ( h + l) /2;

            if (nums[m] > nums[n-1] ) {
                l = m + 1;
            } else {
                h = m - 1;
            }
        }

        cout<<l<<" "<<h<<endl;

        int inter = binarySearch(nums, 0, l-1, target);
        if (inter != -1) return inter;

        return binarySearch(nums, l, n - 1, target);        
    }
};