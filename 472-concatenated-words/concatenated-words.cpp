class Solution {
public:
    bool dfs(string word,unordered_set<string>& dict,unordered_map<string,int>& mp){
        if (mp.find(word) != mp.end()) return mp[word];

        for (int i = 1; i < word.size() ; i++){
            string prefix = word.substr(0,i);
            string postfix = word.substr(i);

            if ((dict.find(prefix) != dict.end() && dict.find(postfix) != dict.end()) ||
                dict.find(prefix) != dict.end() && dfs(postfix,dict,mp)) {
                mp[word] = true;
                return mp[word];
            }
        }

        mp[word] = false;
        return mp[word];
    }


    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string> dict;
        for (auto w: words) dict.insert(w);

        unordered_map<string,int> mp;

        vector<string> ans;

        for (auto w: words){
            if (dfs(w,dict,mp)){
                ans.push_back(w);
            }
        }

        return ans; 
    }
};