class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.length();
        int i = 0;
        int j = 0;

        // vector<int> chars(26,0);
        unordered_map<char,int> mp;
        int count = 0;
        int ans = 0;

        while (j < len){
            mp[s[j]]++;

            if (mp[s[j]] == 1) {
                count++;
            }

            if (count == j - i + 1){
                ans = max(ans,count);
            } else {
                while (count != j - i + 1){
                    mp[s[i]]--;
                    if (mp[s[i]]== 0){
                        count--;
                    }

                    i++;
                }
            }

            j++;
        }

        return ans;
        
    }
};