class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n = nums.size();

        int l = 0;
        int r = n - 1;
        int lowerB = n;
        int upperB = n;

        while (l <= r) {
            int m = l + (r - l)/2;
            if (nums[m] < 0) {
                l = m + 1;
            } else if (nums[m] >= 0) {
                lowerB = m;  //first positive or first zero
                r = m - 1;
            }  
        }


        l = 0;
        r = n - 1;
        while (l <= r) {
            int m = l + (r - l)/2;
            if (nums[m] <= 0) {
                l = m + 1;
            } else if (nums[m] > 0) {
                r = m - 1; 
                upperB = m;  // first postive
            }  
        }

        int negativeCount = lowerB;
        int positiveCount = n - upperB;
        // cout<<lowerB<<" "<<upperB<<endl;

        return max(negativeCount,positiveCount);
             
    }
};