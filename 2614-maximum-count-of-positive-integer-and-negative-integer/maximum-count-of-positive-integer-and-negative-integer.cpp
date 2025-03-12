class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n = nums.size();
        int countN = 0;
        int countP = 0;
        for (auto n: nums){
            if (n > 0) countP++;
            if (n < 0) countN++;
        }

        return max(countP,countN);        
    }
};