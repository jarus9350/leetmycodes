class Solution {
public:
    vector<int> memo;
    int mod = 1e9 + 7;
    int max;
    int count(int curr, int& delay, int& forget){
        if (memo[curr] != -1) return memo[curr];

        int ans = (curr + forget - 1 >= max);
        for (int d = delay ; d < forget ; d++){
            if (curr + d > max ) break;
            ans = (ans + count(curr+d,delay,forget))%mod;
        }

        memo[curr] = ans;
        return ans;
    }
    int peopleAwareOfSecret(int n, int delay, int forget) {
        memo.resize(n+1,-1);
        max = n;
        return count(1,delay,forget);
    }
};