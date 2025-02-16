class Solution {
public:
    bool oneCharChange(string word, string word2){
        int count = 0;
        for (int i = 0 ; i < word.size() ; i++){
            if (word[i] != word2[i]) count++;
            if (count > 1) return false;
        }

        return true;
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int l = wordList.size();

        vector<int> vis(l,0);

        queue<pair<string,int>> q;
        q.push({beginWord,1});

        while (q.size()){
            auto [word, depth] = q.front();
            q.pop();

            if (word == endWord) return depth;

            for (int i = 0; i < l ; i++){
                string w = wordList[i];
                if (!vis[i] && oneCharChange(w, word)) {
                    q.push({w,depth + 1});
                    vis[i] = 1;
                }
            }
        }

        return 0;
    }
};