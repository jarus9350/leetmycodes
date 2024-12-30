class Solution {
public:
    int mod = 1e9 + 7;
    vector<int> memo;
    int dfs(int currLen, int& low, int& high, int& zero, int& one){
        if (currLen == high) return 1;
        if (currLen > high) return 0;
        

        if (memo[currLen] != -1) return memo[currLen];

        int ans = 0;

        if (currLen >= low && currLen <= high) {
            ans++;
        }

        //adding zeros
        ans = (ans + dfs(currLen + zero,low, high, zero, one)) % mod;

        //adding ones
        ans = (ans + dfs(currLen + one, low, high, zero, one)) % mod;

        // cout<<ans<<endl;

        memo[currLen] = ans;

        return memo[currLen];

        // cout<<currLen<<" "<<ans<<endl;

        // return ans;
    }

    int countGoodStrings(int low, int high, int zero, int one) {
        // int a = dfs(0,low,high,zero,one);
        memo.resize(high+1,-1);
        int a = dfs(0,low,high,zero,one);
        // return memo[0];
        return a;
    }
};