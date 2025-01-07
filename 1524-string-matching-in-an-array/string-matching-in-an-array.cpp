class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        int l = words.size();
        set<string> w;

        for (int i = 0 ; i < l ; i++){
            string word1 = words[i];
            for (int j = 0 ; j < l ; j++){
                if (i == j) continue;
                string word2 = words[j];
                if (word1.length() < word2.length()) continue;

                // if (word1.length() == word2.length()) {
                //     if (word1 == word2) w.push_back(word2);
                //     continue;
                // }

                for (int k = 0 ; k < word1.length() ; k++){
                    if (word1.substr(k,word2.length()) == word2) w.insert(word2);
                }
            }
        }

        vector<string> ans;
        for (auto word: w){
            ans.push_back(word);
        }

        return ans;
        
    }
};