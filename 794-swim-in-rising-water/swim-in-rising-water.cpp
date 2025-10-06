class Solution {
public:
    bool possible(vector<vector<int>>& grid,int i,int j,int& p, int& n,vector<vector<int>>&  vis){
        if (i < 0 || i >= n || j < 0|| j >= n) return false;

        if (vis[i][j]) return false;
        if (i == n - 1 && j == n - 1 && (p >= grid[i][j])) return true;
        if (grid[i][j] > p) return false;

        vis[i][j] = 1;
        bool up = possible(grid,i+1,j,p,n,vis);
        bool down = possible(grid,i-1,j,p,n,vis);
        bool left = possible(grid,i,j+1,p,n,vis);
        bool right = possible(grid,i,j-1,p,n,vis);

        return (up || down || left || right)&& ( grid[i][j] <= p)  ;

    }
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int l = 0;
        int h = n*n - 1;
        int ans = -1;
        vector<vector<int>> vis(n,vector<int>(n,0));
        while (l <= h) {
            int m = l + (h - l)/2;
             vector<vector<int>> vis(n,vector<int>(n,0));
            if (possible(grid,0,0,m,n,vis)) {
                ans = m;
                h = m - 1;
            } else {
                l = m + 1;
            }
        }

        return ans;
        
    }
};