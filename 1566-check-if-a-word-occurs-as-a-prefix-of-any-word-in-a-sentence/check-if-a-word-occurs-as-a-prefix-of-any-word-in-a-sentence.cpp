class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        sentence.push_back(' ');
        string word = "";
        int wordCount = 0;
        for (auto c: sentence){
            if (c == ' '){
                if (searchWord == word.substr(0,searchWord.length())){
                    return wordCount + 1;
                };

                if (word.size()){
                    wordCount++;
                }

                word = "";
            } else {
                word.push_back(c);
            }
        }
        

        return -1;
    }
};