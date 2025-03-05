class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        if (n == 1) return strs[0];

        int i = 0;
        for (; i < strs[0].size() ; i++){
            char c = strs[0][i];
            bool found = false;

            for (int j = 1 ; j < strs.size() ; j++){
                string nextWord = strs[j];
                if ( i >= nextWord.size() ) {
                    found = true;
                    break;
                }

                if ( i < nextWord.size() && c != nextWord[i] ) {
                    found = true;
                    break;
                }
            }

            if (found) break;
        }

        string s = strs[0].substr(0,i);
        cout<<s<<endl;

        return s;
    }
};