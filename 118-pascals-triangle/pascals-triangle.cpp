class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;

        ans.push_back({1});
        numRows--;
        int rows = 1;

        while (numRows--){
            vector<int> inter;
            for (int i = 0; i < ans[rows-1].size() ; i++){
                inter.push_back(ans[rows-1][i] + (i-1 >=0 ? ans[rows-1][i-1] : 0));
            }
            inter.push_back(1);
            ans.push_back(inter);
            rows++;
        }

        return ans;
        
    }
};