class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int h = n - 1;

        if (n == 1) return nums[0];

        if (nums[h] > nums[0]) return nums[0];

        while (l <= h) {
            int mid = l + (h - l)/2;

            if (nums[mid] > nums[mid+1]) return nums[mid+1];
            if (nums[mid-1] > nums[mid]) return nums[mid];

            if (nums[mid] > nums[0]) {
                l = mid + 1;
            } else {
                h = mid - 1;
            }
        }

        return -1;        
    }
};