class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n+1,vector<int>(amount+1,0));

        for(int i = 1 ; i <= amount ; i++) dp[0][i] = INT_MAX - 1;

        for (int denomination  = 1 ; denomination <= n ; denomination++) {
            for (int amt = 1; amt <= amount ; amt++ ){
                if (coins[denomination - 1] <= amt){
                    //include
                    int remainingAmt = amt - coins[denomination - 1];
                    int inc = 1 + dp[denomination][remainingAmt];

                    //exclude
                    int exc = dp[denomination-1][amt];

                    dp[denomination][amt] = min(inc,exc);
                } else {
                    dp[denomination][amt] = dp[denomination-1][amt];
                }
            }
        }

        return dp[n][amount] == INT_MAX - 1 ? -1 : dp[n][amount];
    
    }
};