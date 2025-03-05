class Solution {
public:
    bool possible(int i,int j, int n,int m){
        return (i >= 0 && i < n && j >= 0 && j < m);
    }
    
    vector<vector<int>> dir = {{-1,0},{0,-1},{1,0},{0,1}};
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,-1));

        queue<vector<int>> q;
        int count = 0;
        int newCount = 0;

        for (int i = 0 ; i < n ; i++){
            for (int j = 0 ; j < m ; j++){
                if (grid[i][j] == 2){
                    q.push({i,j,0});
                }

                if (grid[i][j] != 0) {
                    count++;
                }
            }
        }


        int ans = 0;

        while (q.size()) {
            auto v = q.front();
            q.pop();

            int i = v[0];
            int j = v[1];
            int time = v[2];

            newCount++;
            ans = max(ans,time);

            for (auto d: dir) {
                int x = i + d[0];
                int y = j + d[1];

                if (possible(x,y,n,m) && grid[x][y] != 2 && grid[x][y] != 0) {
                    grid[x][y] = 2;
                    q.push({x,y,time+1});

                }
            }
        }



        return (count == newCount) ? ans : -1; 
    }
};