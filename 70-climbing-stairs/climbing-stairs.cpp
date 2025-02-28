class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1,0);
        if (n >= 1) dp[1] = 1;
        if (n >= 2) dp[2] = 2;

        if (n == 1 || n == 2) return dp[n];

        for (int i = 3; i <= n ; i++ ){
            dp[i] = dp[i-1] + dp[i-2];
        }

        return dp[n];
    }
};








