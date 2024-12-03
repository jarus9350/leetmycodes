class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string newString = "";
        int spacesIndex = 0;
        for (int i = 0 ; i < s.length(); i++){
            if ( spacesIndex >= spaces.size()){
                newString.push_back(s[i]);
                continue;
            }
            if (i != spaces[spacesIndex]) {
                newString.push_back(s[i]);
            } else {
                newString.push_back(' ');
                spacesIndex++;
                i--;
            }
        }

        return newString;
        
    }
};