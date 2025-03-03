class Solution {
public:
    vector<vector<int>> dir = {{-1,0},{0,-1},{1,0},{0,1}};
    void dfs(vector<vector<int>>& image,int i,int j,int r,int c,int color,int originalColor,vector<vector<int>>& vis){
        if (i < 0 || i >= r || j < 0 || j >= c ) return;
        if (vis[i][j] == 1) return;

        if (image[i][j] != originalColor) return;
        if (image[i][j] == originalColor) image[i][j] = color;
        
        vis[i][j] = 1;
        dfs(image,i+1,j+0,r,c,color,originalColor,vis);
        dfs(image,i-1,j+0,r,c,color,originalColor,vis);
        dfs(image,i+0,j+1,r,c,color,originalColor,vis);
        dfs(image,i+0,j-1,r,c,color,originalColor,vis);
        vis[i][j] = 0;

        return;
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int originalColor = image[sr][sc];
        int r = image.size();
        int c = image[0].size();
        vector<vector<int>> vis(r,vector<int>(c,-1));
        dfs(image,sr,sc,r,c,color,originalColor,vis);
        return image;
    }
};