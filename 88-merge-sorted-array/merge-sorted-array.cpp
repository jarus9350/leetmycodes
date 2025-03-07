class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;

        while ( i >= 0 || j >= 0) {
            int a = (i >= 0) ? nums1[i] : INT_MIN;
            int b = (j >= 0) ? nums2[j] : INT_MIN;

            if (a <= b) {
                nums1[k--] = b;
                j--;
            } else {
                nums1[k--] = a;
                i--;
            }
            // if ( nums1[i] <= nums2[j]) {
            //     nums1[k--] = nums2[j--];
            // } else {
            //     nums1[k--] = nums1[i--];
            // }
        }

        // while ( i >= 0 ){
        //     nums1[k--] = nums1[i--]; 
        // } 
        

        // while ( j >= 0 ){
        //     nums1[k--] = nums2[j--]; 
        // } 

        return;
    }
};