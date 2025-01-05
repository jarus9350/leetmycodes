class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int l = s.length();
        s += 'a';

        vector<int> prefix(l+1,0);

        for (auto s: shifts){
            int start = s[0];
            int end = s[1];
            int direction = s[2];

            if (direction) {
                prefix[start] += 1;
                prefix[end+1] += -1;
            } else {
                prefix[start] += -1;
                prefix[end+1] += 1;
            }
        }

        for (int i = 1 ; i < l ; i++){
            prefix[i] += prefix[i-1];
        }

        for (int i = 0 ; i < l ; i++){
            char ch = s[i];
            int increment = prefix[i]%26;

            int index = ch - 'a';
            int newIndex = (index + increment + 26)% 26;
            int newCh = 'a' + newIndex;

            if (newCh)

            s[i] = newCh;
        }

        s.pop_back();
        return s;
    }
};