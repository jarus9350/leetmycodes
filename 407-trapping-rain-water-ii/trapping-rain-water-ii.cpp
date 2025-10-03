class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        vector<vector<int>> dir = {{0,1},{0,-1},{-1,0},{1,0}};

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        int r = heightMap.size();
        int c = heightMap[0].size();

        for (int i = 0 ; i < r ; i++){
            for (int j = 0 ;  j < c ; j++){
                if (i == 0 || j == 0 || i == r - 1 || j == c - 1) {
                    pq.push({heightMap[i][j], i , j});
                    heightMap[i][j] = -1;
                }
            }
        }
        

        int ans = 0;
        int maxHeight = -1;

        while (pq.size()){
            auto top = pq.top();
            pq.pop();

            int h = top[0];
            int i = top[1];
            int j = top[2];

            maxHeight = max(maxHeight, h);
            ans += maxHeight - h;

            for (auto d: dir) {
                int nx = i + d[0];
                int ny = j + d[1];

                if (nx >= 0 && nx < r && ny >= 0 && ny < c && heightMap[nx][ny] != -1) {
                    pq.push({heightMap[nx][ny],nx,ny});
                    heightMap[nx][ny] = -1;
                }
            }
        }

        return ans;
    }
};