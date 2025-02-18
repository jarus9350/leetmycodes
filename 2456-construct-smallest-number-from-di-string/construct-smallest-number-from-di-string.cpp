class Solution {
public:
    bool check(string perm, string pattern){
        for (int i = 1; i < 9 ; i++){
            if (pattern[i-1] == 'I') {
                if (perm[i] < perm[i-1]) return false;
            } else {
                if (perm[i] > perm[i-1]) return false;
            }
        }

        return true;
    }

    string smallestNumber(string pattern) {
        string s = "";
        for (int i = 1; i <= pattern.length() + 1 ; i++) s +=  (i + '0');
        // cout<<s<<endl;

        while (!check(s,pattern)) {
            next_permutation(s.begin(), s.end());
        }

        return s;    
    }
};