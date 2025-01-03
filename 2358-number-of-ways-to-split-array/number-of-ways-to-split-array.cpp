class Solution {
public:
    int mod = 1e9 + 7;
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();

        vector<long> prefixSum;
        long sum = 0;
        for (int i = 0 ; i < n ; i++){
            sum += nums[i];
            prefixSum.push_back(sum);
        }

        int validSplits = 0;

        for (int i = 0 ; i < n - 1 ; i++){
            long startingSum = prefixSum[i];
            long lastSum = prefixSum[n-1] - prefixSum[i];
            if (startingSum >= lastSum) validSplits++;
        }

        return validSplits;

    }
};