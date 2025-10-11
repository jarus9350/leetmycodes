class Solution {
public:
    unordered_map<long long,long long> powerFreq;
    vector<long long> memo;
    long long ans = INT_MIN;

    long long dp(vector<int>& power, int i ,int& n) {
        if (i >= n) return 0;
        if (memo[i] != -1) return memo[i];

        int j =  lower_bound(power.begin() + i + 1,power.end(),power[i]+3) - power.begin();
        long long take = power[i]*1LL*powerFreq[power[i]] + dp(power,j,n);
        long long leave = dp(power,i+1,n);

        memo[i] = max(take,leave);

        ans = max(ans,memo[i]);
        return memo[i];
    }

    long long maximumTotalDamage(vector<int>& power) {
        sort(power.begin(),power.end());
        for (auto p: power) powerFreq[p]++;

        int n = power.size();
        memo.resize(100001,-1);
        dp(power,0,n);
        return ans;

    }
};