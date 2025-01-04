class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int l = s.length();

        // unordered_map<int,pair<int,int>> charfirstLast;

        // for (int i = 0 ; i < l ; i++){
        //     char c = s[i];
        //     if (charfirstLast.find(c) == charfirstLast.end()){
        //         charfirstLast[c] = {i,i};
        //     } else {
        //         charfirstLast[c] = {charfirstLast[c].first,i};
        //     }
        // }

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

        set<string> ans;

        for (int i = 1 ; i < l - 1 ; i++){
            char c = s[i];
            for (int j = 0 ; j < 26 ; j++){
                char alpha = 'a' + j;
                string inter = "";

                if (first[j] == -1) continue;

                int f = first[j];
                int l = last[j];

                    if (f < i && l > i){
                        inter += alpha;
                        inter += c;
                        inter += alpha;
                        ans.insert(inter);
                    }
            }

        }

        return ans.size();

    }
};