class Solution {
public:
    int commonWordLength;
    int mod = 1e9 + 7;
    vector<vector<long>> memo;
    vector<vector<int>> freq;

    long helper(int i,string& target,int nextIndex, vector<string>& words){
        if (i == target.size()) return 1; 
        if (nextIndex == commonWordLength) return 0;
        //if (words[0].size() - nextIndex < target.size() - i) return 0;

        if (memo[i][nextIndex] != -1) return memo[i][nextIndex];

        char ch = target[i];
        long ans = 0;

        int f = freq[nextIndex][ch - 'a'];

        ans = (ans + f*(helper(i+1,target,nextIndex+1,words)%mod)) % mod;
        ans = (ans + helper(i,target,nextIndex+1,words)) % mod;

        /*
        for (int j = 0 ; j < words.size(); j++){
            string word = words[j];
            for (int k = nextIndex ; k < word.length() ; k++){
                if (ch == word[k]){
                    ans = (ans + helper(i+1,target,k+1, words)) % mod;
                }
            }
        }
        */

        return memo[i][nextIndex] = ans;

    }
    int numWays(vector<string>& words, string target) {
        commonWordLength = words[0].size();
        int n = target.length();
        memo.resize(n+1,vector<long>(commonWordLength+1,-1));

        freq.resize(commonWordLength,vector<int>(26,0));

        for (int i = 0 ; i < words.size(); i++){
            for (int j = 0 ; j < words[i].size() ;  j++){
                freq[j][words[i][j] - 'a']++;
            }
        }
        
        int a = helper(0,target,0,words);

        return a;
        
    }
};