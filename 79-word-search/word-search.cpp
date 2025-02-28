class Solution {
public:
    bool ans = false;
    void dfs(int i, int j, int& m, int& n,vector<vector<char>>& board,string& word,int index,vector<vector<int>>& vis){
        if (i < 0 || i >= m || j < 0 || j >= n) return;
        if (vis[i][j]) return;

        if (index > word.size() - 1) return;
        if (index == word.size() - 1 && word[index] == board[i][j]) {
            ans = true;
            return;
        }

        if (word[index] == board[i][j]){
            vis[i][j] = 1;
            dfs(i,j+1,m,n,board,word,index+1,vis);
            dfs(i+1,j,m,n,board,word,index+1,vis);
            dfs(i,j-1,m,n,board,word,index+1,vis);
            dfs(i-1,j,m,n,board,word,index+1,vis);
            vis[i][j] = 0;
        }

        return;
    }


    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        if (m*n < word.size()) return false;

        vector<vector<int>> vis(m,vector<int>(n,0));

        for (int i = 0 ; i < m ; i++){
            for (int j = 0 ; j < n ; j++){
                if (board[i][j] == word[0]){
                    dfs(i,j,m,n,board,word,0,vis);
                }

                if (ans) {
                    break;
                }
                
            }
        }

        return ans;
        
    }
};