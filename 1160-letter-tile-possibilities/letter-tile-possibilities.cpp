class Solution {
public:
    void recursion(int index,string a,int& ans, vector<int>& chars,int& n){
        if (index == n){
            ans++;
            return;
        }

        ans++;
        for (int i = 0 ; i < 26 ; i++){
            char c = 'A' + i;
            int times = chars[i];

            if (times == 0)  continue;

            a.push_back(c);
            chars[i]--;
            recursion(index + 1, a, ans, chars, n);


            a.pop_back();
            chars[i]++;
        }

    }
    int numTilePossibilities(string tiles) {
        vector<int> chars(26,0);
        int n = tiles.length();
        for (auto c: tiles) chars[c-'A']++;

        int ans = 0;
        recursion(0,"",ans,chars,n);
        return ans - 1;
    }
};