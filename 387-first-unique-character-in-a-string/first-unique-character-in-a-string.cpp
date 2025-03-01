class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> chars(26,-1);
        int mini = INT_MAX;

        for (int i = 0 ; i < s.length() ; i++ ){
            char ch = s[i];

            int index = ch - 'a';

            if (chars[index] == -1) {
                chars[index] = i;
            } else if (chars[index] != -1){
                chars[index] = -2;
            } 
        }

        for (int i = 0 ; i < 26 ; i++){
            if (chars[i] != -1 && chars[i] != -2) {
                mini = min(mini,chars[i]);
            }
        }


        return mini == INT_MAX ? -1 : mini;
        
    }
};