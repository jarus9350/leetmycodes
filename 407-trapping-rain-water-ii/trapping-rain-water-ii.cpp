class Solution {
public:
    bool isValid(int i, int j , int& r, int& c){
        return (i >=0 && i < r && j >= 0 && j < c);
    }

    int trapRainWater(vector<vector<int>>& heightMap) {
        int r = heightMap.size();
        int c = heightMap[0].size();

        vector<vector<int>> dir = {{0,1},{1,0},{0,-1},{-1,0}};

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        for (int i = 0 ; i < r ; i++){
            for (int j = 0 ; j < c ; j++){
                if ( i == 0 || i == r - 1 || j == 0 || j == c - 1){
                    pq.push({heightMap[i][j],i,j});
                    heightMap[i][j] = -1; //mark visited
                }
            }
        }

        int maxVal = 0;
        int totalVolume = 0;

        while (pq.size()){
            auto top = pq.top();
            pq.pop();

            int h = top[0];
            int i = top[1];
            int j = top[2];

            maxVal = max(maxVal,h);
            totalVolume += maxVal - h;

            for (auto d: dir){
                int x = i + d[0];
                int y = j + d[1];
                
                if (isValid(x,y,r,c) && heightMap[x][y] != -1){
                    pq.push({heightMap[x][y],x,y});
                    heightMap[x][y] = -1;
                }

            }


        }

        return totalVolume;
        
    }
};