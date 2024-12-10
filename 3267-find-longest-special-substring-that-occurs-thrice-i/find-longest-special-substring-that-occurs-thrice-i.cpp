class Solution {
public:
    int maximumLength(string s) {
        unordered_map<string,int> mp;

        // for (int i = 1 ; i <= s.length() ; i++ ){

        // }
        int ans = 0;

        for (int g = 0 ; g < s.length() ; g++){
            for (int i = 0, j = g; j < s.length() ; i++,j++){
                string subString = s.substr(i,j-i+1);
                mp[subString]++;
            }
        }

        for (auto m: mp){
            string sub = m.first;
            int freq = m.second;
            int len = sub.length();

            bool same = true;
            for (int i = 1 ; i < sub.length(); i++){
                if (sub[i] != sub[i-1]){
                    same = false;
                    break;
                }
            }

            if (same){
                if (freq >= 3){
                    ans = max(ans,len);
                }
            }
        }
        
        return ans == 0 ? -1 : ans;
    }
};