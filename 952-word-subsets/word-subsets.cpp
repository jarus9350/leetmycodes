class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> freq(26,0);

        for (auto w: words2){
            vector<int> interFreq(26,0);

            for (auto ch: w){
                interFreq[ch-'a']++;
            }

            for (int i = 0 ; i < 26 ; i++){
                freq[i] = max(freq[i],interFreq[i]);
            }
        }

        // for (auto c: freq){
        //     cout<<c<<" ";
        // }
        // cout<<endl;

        vector<string> ans;

        for (auto w : words1){
            auto inter = freq;

            vector<int> interFreq(26,0);

            for (auto ch: w){
                interFreq[ch-'a']++;
            }

            bool possible = true;
            for (int i = 0 ; i < 26 ; i++){
                int a = interFreq[i] - inter[i];
                if ( a < 0) possible = false;
            }

            if (possible) ans.push_back(w);

        }

        return ans;
    }
};