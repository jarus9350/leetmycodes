class Solution {
public:
    int maxScore(string s) {
        int n = s.length();
        vector<int> backs(n,0);

        backs[n-1] =  (s[n-1] == '1' ? 1 : 0);
        for (int i = n - 2 ; i >=0 ; i--){
            backs[i] = backs[i+1] + (s[i] == '1' ? 1: 0);
        }

        int count = 0;
        int maxScore = INT_MIN;
        for (int i = 0 ; i < n - 1; i++){
            if (s[i] == '0') {
                count++;
            }
            maxScore = max(maxScore, count + backs[i+1]);
            // cout<<maxScore<<" ";
        }

        return maxScore;
        
    }
};