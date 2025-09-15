class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        vector<int> broken(26,0);
        
        for (auto c: brokenLetters){
            broken[c-'a']++;
        }

        int count = 0;
        string word = "";
        for (int i = 0 ; i < text.length() ; i++){
            if (text[i] == ' '){
                if (word != "") count++;
            } else {
                if (broken[text[i]-'a']) {
                    while ( i < text.length() && text[i] != ' ') {
                        i++;
                    }
                    word = "";
                } else {
                    word.push_back(text[i]);
                }

            }


        }

        if (word != "") count++;
        return count;
        
    }
};