class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int h = 0;

        int longestIncreasing = 0;
        int longestDecreasing = 0;
        vector<int> vec;
        vector<int> dec;
        while (h < n) {
            
            if (!dec.size()) {
                dec.push_back(nums[h]);
                h++;
                int s = dec.size();
                longestIncreasing = max(longestIncreasing, s);
            } else {
                if (dec.back() < nums[h]){
                    dec.push_back(nums[h]);
                    h++;
                    int s = dec.size();
                    longestIncreasing = max(longestIncreasing, s);
                } else {
                    while (dec.size()) dec.pop_back();
                }
            }
        }

        l = 0;
        h = 0;

        while (h < n) {
            if (!vec.size()) {
                vec.push_back(nums[h]);
                h++;
                int s = vec.size();
                longestIncreasing = max(longestIncreasing, s);
            } else {
                if (vec.back() > nums[h]){
                    vec.push_back(nums[h]);
                    h++;
                    int s = vec.size();
                    longestIncreasing = max(longestIncreasing, s);
                } else {
                    while (vec.size()) vec.pop_back();
                }
            }
        }

        return longestIncreasing;
    }
};