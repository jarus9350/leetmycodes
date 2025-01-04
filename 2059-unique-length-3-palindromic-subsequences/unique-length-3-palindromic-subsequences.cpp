class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int l = s.length();

        vector<int> first(26,-1);
        vector<int> last(26,-1);

        for (int i = 0 ; i < l ; i++){
            char c = s[i];

            int index = c - 'a';
            if (first[index] == -1) {
                first[index] = i;
                last[index] = i;
            }

            if (last[index] != -1){
                last[index] = i;
            }
        }

        int ans = 0;
        
        for (int i = 0 ; i < 26 ; i++){
            int f = first[i];
            int l = last[i];

            if (f == -1) continue;

            unordered_set<char> hash;
            for (int j = f + 1 ; j < l ; j++){
                hash.insert(s[j]);
            }

            ans += hash.size();
        }

        return ans;

    }
};