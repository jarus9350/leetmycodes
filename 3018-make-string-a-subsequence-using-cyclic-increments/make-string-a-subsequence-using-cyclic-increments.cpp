class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int n1 = str1.length();
        int n2 = str2.length();

        int i = 0;
        int j = 0;
        
        while ( i < n1 && j < n2){
            if (str1[i] == str2[j]){
                i++;
                j++;
            } else if (str1[i] != str2[j]){
                str1[i] = (char)( 'a' + (((str1[i] - 'a') + 1)%26) );
                if (str1[i] == str2[j]){
                    i++;
                    j++;
                } else {
                    i++;
                }
            }
        }

        if (i >= n1 && j < n2) return false;
        return true;
        
    }
};