class Solution {
public:
    bool isValid(int x, int y , int& r, int& c){
        return (x >=0 && x < r && y >= 0 && y < c);
    }

    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int r = isWater.size();
        int c = isWater[0].size();

        priority_queue<vector<int>,vector<vector<int>>, greater<vector<int>>> pq;

        vector<vector<int>> heights(r,vector<int>(c,0));
        vector<vector<int>> dir = {{0,1},{1,0},{0,-1}, {-1,0}};

        for (int i = 0 ; i < r ; i++){
            for (int j = 0 ; j < c ; j++){
                if (isWater[i][j] == 1) {
                    pq.push({0,i,j});
                    isWater[i][j] = -1;
                }
            }
        }

        while (!pq.empty()){
            auto top = pq.top();
            pq.pop();

            int height = top[0];
            int i = top[1];
            int j = top[2];

            heights[i][j] = height;

            for (auto d: dir){
                int x = i + d[0];
                int y = j + d[1];

                if (isValid(x,y,r,c) && !isWater[x][y]){
                    pq.push({height+1,x,y});
                    isWater[x][y] = 1;
                }
            }


        }

        return heights;
        
    }
};