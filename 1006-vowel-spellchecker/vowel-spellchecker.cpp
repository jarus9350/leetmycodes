class Solution {
public:
    bool isVowel(char& c) {
        return ( c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' );
    }

    pair<string,string> genKey(string s){
        string key = "";
        string val = "";
        int num = 0;
        for (char c: s){
            char lowerC = tolower(c);
            if (isVowel(lowerC)){
                num++;
            } else {
                val += c;
                if (num == 0) {
                    key += lowerC;
                } else {
                    key += to_string(num);
                    num = 0;
                    key += lowerC;
                }
            }
        }

        if (num != 0) {
            key += to_string(num);
        }

        return {key,s};
    }

    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        set<string> wl;
        unordered_map<string,string> mp;
        unordered_map<string,string> caseSensitiveMap;

        for (auto w: wordlist){
            wl.insert(w);

            string lwrC = "";
            for (auto ch: w){
                lwrC.push_back(tolower(ch));
            }
            if (caseSensitiveMap.find(lwrC) == caseSensitiveMap.end()) {
                caseSensitiveMap[lwrC] = w;
            }

            auto [key,val] = genKey(w);
            if (mp.find(key) == mp.end()) {
                mp[key] = val;
            }
        }

        vector<string> ans;

        for (auto word: queries) {
            string lc = "";
            for (auto ch: word){
                lc.push_back(tolower(ch));
            }

            if (wl.find(word) != wl.end()) {
                ans.push_back(word);
            } else if (lc != "" && caseSensitiveMap.find(lc) != caseSensitiveMap.end()){
                ans.push_back(caseSensitiveMap[lc]);
            } else {
                auto [key,val] = genKey(word);

                if (mp.find(key) == mp.end()) {
                    ans.push_back("");
                    continue;
                } else {
                    ans.push_back(mp[key]);
                }
            }
        }


        return ans;
    }
};