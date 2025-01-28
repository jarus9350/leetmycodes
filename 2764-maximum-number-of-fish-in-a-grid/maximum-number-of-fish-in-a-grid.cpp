class Solution {
public:
    vector<vector<int>> dir = {{0,1},{1,0},{-1,0},{0,-1}};
    bool isValid(int i,int j, int m, int n){
        return (i >=0 && i < m && j >=0 && j< n);
    }

    int BFS(int i,int j,vector<vector<int>>& vis,vector<vector<int>>& grid,int& m, int& n){
        queue<vector<int>> q;
        q.push({i,j,grid[i][j]});
        vis[i][j] = 1;

        int ans = INT_MIN;

        while (!q.empty()){
            auto front = q.front();
            q.pop();

            int i = front[0];
            int j = front[1];
            int val = front[2];

            ans = max(ans,val);

            for (auto d: dir){
                int x = i + d[0];
                int y = j + d[1];

                if (isValid(x,y,m,n) && !vis[x][y] && grid[x][y]) {
                    q.push({x,y,val + grid[x][y]});
                    vis[x][y] = 1;
                }

            }
        }

        return ans;
    }

    int DFS(int i,int j,vector<vector<int>>& vis,vector<vector<int>>& grid,int& m, int& n){
       if (i < 0 || i >= m || j < 0 || j >= n) return 0;
       if (grid[i][j] == 0) return 0;

        int temp = grid[i][j];
        grid[i][j] = 0;

        int a = DFS(i+1,j,vis,grid,m,n);
        int b = DFS(i-1,j,vis,grid,m,n);
        int c = DFS(i,j+1,vis,grid,m,n);
        int d = DFS(i,j-1,vis,grid,m,n);

        return temp + a + b + c + d;
    }

    int findMaxFish(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> vis(m,vector<int>(n,0));
        int ans = INT_MIN;
        for (int i = 0 ; i < m ; i++){
            for (int j = 0 ; j < n ; j++){
                if (!vis[i][j] && grid[i][j]) {
                    ans = max(ans,DFS(i,j,vis,grid,m,n));
                }
            }
        }

        return ans == INT_MIN ? 0 : ans;
        
    }
};