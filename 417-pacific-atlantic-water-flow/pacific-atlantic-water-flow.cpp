class Solution {
public:
    void dfs(vector<vector<int>>& heights, vector<vector<int>>& reach,int i,int j, int r, int c,int prev){
        if (i < 0 || i >= r || j < 0 || j >= c) return ;
        if ( heights[i][j] < prev) return;
        if (reach[i][j]) return;

        reach[i][j] = 1;
        dfs(heights,reach,i+1,j,r,c, heights[i][j]);
        dfs(heights,reach,i-1,j,r,c, heights[i][j]);
        dfs(heights,reach,i,j+1,r,c, heights[i][j]);
        dfs(heights,reach,i,j-1,r,c, heights[i][j]);

        

        return;

    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int r = heights.size();
        int c = heights[0].size();

        vector<vector<int>> reachAtlantic(r,vector<int>(c,0));
        vector<vector<int>> reachPacific(r,vector<int>(c,0));

        for (int i = 0 ; i < r ; i++){
            for (int j = 0; j < c ; j++){
                if (i == 0 || j == 0 ){
                    dfs(heights,reachPacific,i,j,r,c,0);
                }
                if (i == r - 1 || j == c - 1) {
                    dfs(heights,reachAtlantic,i,j,r,c,0);
                }
            }
        }

        // for (int i = 0 ; i < r ; i++){
        //     for (int j = 0; j < c ; j++){
        //         if (i == 0 || j == 0 ){
        //             dfs(heights,reachPacific,i,j,r,c,0);
        //         }
        //     }
        // }

        vector<vector<int>> ans;
        for (int i = 0 ; i < r ; i++){
            for (int j = 0 ; j < c ; j++){
                if (reachPacific[i][j] && reachAtlantic[i][j]) {
                    cout<<i<<" "<<j<<endl;
                    ans.push_back({i,j});
                }
            }
        }

        return ans;

        
    }
};