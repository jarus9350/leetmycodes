class Solution {
public:
    vector<vector<int>> dir = {{1,0},{0,1},{-1,0},{0,-1}};

    bool isValid(int i,int j,int m,int n){
        return (i >= 0 && j >= 0 && i < m && j < n);
    }

    void dfs(int i,int j,int& m,int& n,vector<vector<char>>& grid){
        if (i < 0 || j < 0 || i >= m || j >= n) return;
        if (grid[i][j] == '0') return;
         if (grid[i][j] == '2') return;

        grid[i][j] = '2';

        for (auto d: dir){
            int x = i + d[0];
            int y = j + d[1];

            if (isValid(x, y, m, n) && grid[x][y] == '1') {
                dfs(x,y,m,n,grid);
            }
        }

        return;
    }


    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int count = 0;

        for (int i = 0; i < m ; i++){
            for (int j = 0; j < n ; j++){
                if (grid[i][j] == '1'){
                    dfs(i,j,m,n,grid);
                    count++;
                }
            }
        }

        return count;
    }
};
