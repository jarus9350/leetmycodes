class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int s = prices.size();

        int allTimeLow = prices[0];
        int ans = 0;

        for (int i = 1 ; i < s ; i++){
            int sellAt = prices[i];
            int minBefore = allTimeLow;
            if (sellAt >= minBefore) {
                ans = max(ans, sellAt - minBefore);
            }
            allTimeLow = min(minBefore,sellAt);
        }

        return ans;
        
    }
};