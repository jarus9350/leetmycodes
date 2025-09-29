class Solution {
public:
    vector<vector<int>> memo;
    int solve(vector<int>& values, int i, int j){
        if (memo[i][j] != -1) return memo[i][j];

        if (j - i == 1) return 0;

        long long ans = INT_MAX;
        for (int k = i+1 ; k < j ; k++){
            long long inter = solve(values,i,k) + values[i]*values[j]*values[k] + solve(values,k,j);
            ans = min(ans,inter);
        }

        memo[i][j] = ans;

        return ans;
    }
    int minScoreTriangulation(vector<int>& values) {
        long long ans = INT_MAX;

        memo.resize(values.size(),vector<int>(values.size(),-1));

        int i = 0;
        int j = values.size() - 1;

        for (int k = i + 1 ; k < j ; k++){
            long long inter = solve(values,i,k) + (long long)values[i]*(long long)values[j]*(long long)values[k] + solve(values,k,j);
            ans = min(ans,inter);
        }
        
        return ans;
    }
};