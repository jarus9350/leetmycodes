class Solution {
public:
    vector<vector<int>> dir = {{1,0},{0,1},{-1,0},{0,-1}};

    bool possible(int i,int j,int m,int n){
        return (i >= 0 && i < m && j >= 0 && j < n);
    }

    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<int>> distances(m,vector<int>(n,INT_MAX));
        vector<vector<int>> visited(m,vector<int>(n,0));

        distances[0][0] = 0;

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0,0,0});
        visited[0][0] = 1;

        while(pq.size()){
            auto top = pq.top();
            pq.pop();
            int cost = top[0];
            int x = top[1];
            int y = top[2];
            visited[x][y] = 1;

            for (auto d: dir){
                int i = x + d[0];
                int j = y + d[1];
                if (possible(i,j,m,n) && !visited[i][j]){
                    int currentDiff = abs(heights[i][j] - heights[x][y]);
                    int maxDiff = max(currentDiff,cost);

                    if (distances[i][j] > maxDiff){
                        distances[i][j] = maxDiff;
                        pq.push({distances[i][j],i,j});
                    }
                }
            }
        }

        // for (auto a: distances){
        //     for(auto b: a){
        //         cout<<b<<" ";
        //     }
        //     cout<<endl;
        // }
        // cout<<endl;


        // cout<<distances[m-1][n-1]<<endl;

        return distances[m-1][n-1];
        
    }
};