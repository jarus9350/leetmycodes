class Solution {
public:
    vector<vector<int>> dir = {{0,-1},{-1,0},{0,1},{1,0}};
    bool possible(int x,int y,int m,int n,vector<vector<int>>& visited){
        // && !visited[x][y]
        return (x >= 0 && x < m && y >= 0 && y < n && !visited[x][y]) ;
    }

    int minimumTime(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> distances(m,vector<int>(n,INT_MAX));
        vector<vector<int>> visited(m,vector<int>(n,0));

        distances[0][0] = 0;

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0,0,0});
        visited[0][0] = 1;

        while (pq.size()){
            auto top = pq.top();
            pq.pop();

            int d = top[0];
            int i = top[1];
            int j = top[2];

            int wayOut = 0;
            for (auto d: dir){
                int x = i + d[0];
                int y = j + d[1];

                if (possible(x,y,m,n,visited)){
                    if (distances[i][j] == INT_MAX) {
                        continue;
                    }

                    if (i == 0 && j == 0) {
                        if (grid[x][y] > 1) {
                            wayOut++;
                        }
                    }

                    if (distances[i][j] + 1 < distances[x][y]){
                        distances[x][y] = distances[i][j] + 1;

                        if (grid[x][y] > distances[i][j]) {
                            if ( (grid[x][y] - distances[i][j]) % 2 == 1) {
                                distances[x][y] = grid[x][y];
                            } else {
                                distances[x][y] = grid[x][y] + 1;
                            }
                        }

                        pq.push({distances[x][y],x,y});
                        visited[x][y] = 1;
                    }
                }
            }
                
            if (wayOut == 2) return -1;
        }

        // for (auto b: distances){
        //     for (auto a: b){
        //         cout<<a<<" ";
        //     }
        //     cout<<endl;
        // }


        return distances[m-1][n-1] == INT_MAX ? -1 : distances[m-1][n-1];
        
    }
};

