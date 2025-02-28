class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.length();
        vector<vector<int>> dp(len,vector<int>(len,0));

        int ans = 0;
        int st = 0;
        int ed = 0;

        for (int g = 0 ; g < len ; g++){
            for (int i = 0, j = g ; j < len ; i++, j++){
                if (g == 0) {
                    dp[i][j] = 1;
                } else if (g == 1) {
                    dp[i][j] = s[i] == s[j];
                } else {
                    dp[i][j] = s[i] == s[j] && dp[i+1][j-1];
                }

                if (dp[i][j]) {
                    ans = max(ans,j-i+1);
                    st = i;
                    ed = j;
                }
            }
        }

        return s.substr(st,ed-st+1);
        
    }
};