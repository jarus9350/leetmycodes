class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        vector<int> broken(26,0);
        
        for (auto c: brokenLetters){
            broken[c-'a']++;
        }

        int count = 0;
        string word = "";
        bool b = false;
        for (int i = 0 ; i < text.length() ; i++){
            if (text[i] == ' '){
                if (word != "" && !b) {
                    count++;
                }
                word = "";
                b = false;
            } else {
                word.push_back(text[i]);
                if (broken[text[i]-'a']) {
                    b = true;
                }
            }
        }

        if (word != "" && !b) {
                    count++;
                }

        return count;
        
    }
};