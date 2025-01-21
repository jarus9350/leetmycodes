class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();

        vector<long long> row1(c,0);
        vector<long long> row2(c,0);

        long long s = 0;
        for (int i = 0 ; i < c ; i++){
            s += grid[0][i];
            row1[i] = s;
        }

        s = 0;
        for (int i = c-1 ; i >= 0 ; i--){
            s += grid[1][i];
            row2[i] = s;
        }

        // for (auto c : row1){
        //     cout<<c<<" ";
        // }
        // cout<<endl;

        // for (auto c : row2){
        //     cout<<c<<" ";
        // }
        // cout<<endl;

        long long sum = 0;
        long long ans = 10000000007;
        for (int i = 0 ; i < c ; i++){
            long long leftSum = row1[i];
            long long rightSum = row2[i];
            // if (leftSum + rightSum > sum){
            //     sum = leftSum + rightSum;
            //     long long leftRem = row1[c-1] - leftSum;
            //     long long rightRem = row2[0] - rightSum;
            //     ans = max(leftRem,rightRem);
            //     cout<<i<<" "<<ans<<" "<<leftRem<<" "<<rightRem<<endl;
            //     cout<<i<<" "<<sum<<endl;
            // }

            long long leftRem = row1[c-1] - leftSum;
            long long rightRem = row2[0] - rightSum;
            ans = min(ans,max(leftRem,rightRem));

            // cout<<i<<" "<<ans<<" "<<leftRem<<" "<<rightRem<<endl;
            // cout<<i<<" "<<sum<<endl;
        }

        return ans;
        
    }
};