class Solution {
public:
    int DFS(int i,int j,vector<vector<int>>& grid,int& m, int& n){
       if (i < 0 || i >= m || j < 0 || j >= n) return 0;
       if (grid[i][j] == 0) return 0;

        int temp = grid[i][j];
        grid[i][j] = 0;

        int a = DFS(i+1,j,grid,m,n);
        int b = DFS(i-1,j,grid,m,n);
        int c = DFS(i,j+1,grid,m,n);
        int d = DFS(i,j-1,grid,m,n);

        return temp + a + b + c + d;
    }

    int findMaxFish(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int ans = INT_MIN;
        for (int i = 0 ; i < m ; i++){
            for (int j = 0 ; j < n ; j++){
                if (grid[i][j]) {
                    ans = max(ans,DFS(i,j,grid,m,n));
                }
            }
        }

        return ans == INT_MIN ? 0 : ans;
        
    }
};