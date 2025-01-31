class Solution {
public:

    vector<vector<int>> dir = {{0,1},{1,0},{0,-1},{-1,0}};

    bool isValid(int x, int y, int n){
        return (x >= 0 && x < n && y >= 0 && y < n);
    }


    int BFS(int i,int j,vector<vector<int>>&  grid,int areacode){
        int n = grid.size();

        queue<vector<int>> q;
        q.push({i,j});
        grid[i][j] = areacode;

        int ans = 0;

        while(q.size()){
            auto front = q.front();
            q.pop();
            int i = front[0];
            int j = front[1];

            ans++;

            for (auto d: dir){
                int x = i + d[0];
                int y = j + d[1];

                if (isValid(x,y,n) && grid[x][y] != 0  && grid[x][y] != areacode) {
                    q.push({x,y});
                    grid[x][y] = areacode;
                }
            }
        }

        return ans;
    }

    int connector(int i,int j,int n,map<int,int>& codeSize,vector<vector<int>>& grid){
        set<int> uniqueAreas;
        int ans = 0;

        for (auto d: dir){
            int x = i + d[0];
            int y = j + d[1];

            if (isValid(x, y, n)){
                int code = grid[x][y];
                if (uniqueAreas.find(code) == uniqueAreas.end()){
                    uniqueAreas.insert(code);
                    ans += codeSize[code];
                }
            }
        }

        return ans;
    }


    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int ans = 0;

        //precompute areas
        map<int,int> codeSize;
        int areacode = 2;
        for (int i = 0 ; i < n ; i++){
            for (int j = 0 ; j < n ; j++){
                if (grid[i][j] == 1) {
                    int size = BFS(i,j,grid,areacode);
                    // cout<<size<<" "<<i<<" "<<j<<endl;
                    codeSize[areacode] = size;
                    areacode++;
                }
            }
        }

        bool found = false;
        for (int i = 0; i < n ; i++){
            for (int j = 0 ; j < n ; j++){
                if (grid[i][j] == 0) {
                    found = true;
                    int inter = 1 + connector(i,j,n,codeSize,grid);
                    ans = max(ans,inter);
                }
            }
        }

        if (!found) return n*n;

        return ans;
        
    }
};