class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        vector<int> freq(26,0);
        for (auto c: s ){
            freq[c-'a']++;
        }

        vector<vector<int>> charFreq;
        for (int i = 0 ; i < 26 ; i++){
            if (freq[i]){
                charFreq.push_back({i,freq[i]});
            }
        }

        sort(charFreq.begin(),charFreq.end(),greater<vector<int>>());

        // for (int i = 0 ; i < charFreq.size() ; i++){
        //     cout<<(char)(charFreq[i][0] + 'a')<<" "<<charFreq[i][1]<<endl;
        // }

        string ans = "";

        bool same = false;
        for (int i = 0 ; i < charFreq.size() ; i++){
            // if (!charFreq[i][1]) continue;
            if (charFreq[i][1] > repeatLimit){
                same = true;

                for (int j = 0 ; j < repeatLimit ; j++){
                    ans += charFreq[i][0] + 'a';
                }

                charFreq[i][1] = charFreq[i][1] - repeatLimit;
            } else {
                for (int j = 0 ; j < charFreq[i][1]; j++){
                    ans += charFreq[i][0] + 'a';
                }

                charFreq[i][1] = 0;

                same = false;
            }

            if (same){
                //find next character which is not zero
                // ans += charFreq[i+1][0] + 'a';
                // charFreq[i+1][1]--;
                // i--;

                //find next character which is not zero
                bool found = false;
                for (int j = i + 1 ; j < charFreq.size() ; j++){
                    if (charFreq[j][1]){
                        found = true;
                        ans += charFreq[j][0] + 'a';
                        charFreq[j][1]--;
                        break;
                    }
                }

                if (found) {
                    i--;
                }

                
            }
        }

        /*
        int consecutive = 1;
        for (int i = ans.length() - 1 ; i >= 0 ; i--){
            if (i + 1 < ans.length() && ans[i] == ans[i+1]){
                consecutive++;
                if (consecutive > repeatLimit){
                    int foundIndex = i;
                    ans.substr(0,)
                }
            }
        }
        */

        return ans;
    }
};