class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int s1 = nums1.size() % 2;
        int s2 = nums2.size() % 2;

        int xorNums1 = nums1[0];
        for (int i = 1 ; i < nums1.size() ; i++){
            xorNums1 = xorNums1 ^ nums1[i];
        }

        int xorNums2 = nums2[0];
        for (int i = 1 ; i < nums2.size() ; i++){
            xorNums2 = xorNums2 ^ nums2[i];
        }

        if (!s1 && !s2) return 0;
        if (s1 && s2) {
            return xorNums1 ^ xorNums2;
        } 

        if (s1) {
            return xorNums2;
        } else {
            return xorNums1;
        }
        
    }
};