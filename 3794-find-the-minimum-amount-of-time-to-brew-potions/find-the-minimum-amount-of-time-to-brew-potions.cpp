class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n = skill.size();
        int m = mana.size();

        vector<long long> prev(n,0);

        long long p = 0;
        for (int i = 0 ; i < n ; i++) {
            prev[i] = p + skill[i]*mana[0];
            p = prev[i];
        }

        for (int j = 1 ; j < mana.size() ; j++) {
            int juice = mana[j];


            prev[0] = prev[0] + skill[0]*juice;
            long long p = prev[0];
            for (int i = 1 ; i < n ; i++) {
                prev[i] = max(prev[i-1], prev[i]) + skill[i]*juice;
            }

            for (int i = n - 2; i >= 0 ; i--){
                prev[i] = prev[i+1] - skill[i+1]*juice;
            }
        }
        

        for (auto s: prev) {
            cout<<s<<" ";
        }
        cout<<endl;

        return prev[n-1];
        
    }
};