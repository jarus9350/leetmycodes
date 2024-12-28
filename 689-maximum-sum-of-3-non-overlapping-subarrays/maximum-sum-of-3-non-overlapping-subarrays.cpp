class Solution {
public:
    vector<int> ans;
    vector<vector<int>> memo;
    void findPath(int i, int& n, int k, int count, vector<int>& prefixSum){
        if (count == 3) return;
        if (i == n ) return;

        //starting at index i
        int sum = 0;
        int inc = 0;
        if (i + k - 1 < n) {
            sum = prefixSum[i+k-1]  -  ( i - 1 >= 0 ? prefixSum[i-1] : 0);
            inc = sum + zeroOneKnapsack(i+k, n, k, prefixSum, count+1); // 0(1)
        }
        
        //not taking index i
        int exc = zeroOneKnapsack(i+1, n, k, prefixSum, count); // 0(1)

        if (inc >= exc){
            ans.push_back(i);
            findPath(i+k, n, k, count+1, prefixSum);
        } else {
            findPath(i+1, n, k, count, prefixSum);
        }

    }

    int zeroOneKnapsack(int i, int& n, int k, vector<int>& prefixSum,int count){
        if (count == 3) return 0;
        if (i == n ) return INT_MIN;

        if (memo[i][count] != -1) return memo[i][count];

        //starting at index i
        int sum = 0;
        int inc = 0;
        if (i + k - 1 < n) {
            sum = prefixSum[i+k-1]  -  ( i - 1 >= 0 ? prefixSum[i-1] : 0);
            inc = sum + zeroOneKnapsack(i+k, n, k, prefixSum, count+1);
        }
        
        //not taking index i
        int exc = zeroOneKnapsack(i+1, n, k, prefixSum, count);

        return memo[i][count] = max(inc,exc);
    }

    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> prefixSum(n,0);
        memo.resize(20001,vector<int>(4,-1));

        for (int i = 0 ; i < n; i++) prefixSum[i] = ((i - 1 >= 0 ) ? prefixSum[i-1] : 0) + nums[i];

        int maxSum = zeroOneKnapsack(0, n, k, prefixSum, 0);



        //greedily looking for path
        findPath(0, n, k, 0,prefixSum);

        return ans;
    }
};