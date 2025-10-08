class Solution {
public:
    int bs(vector<int>& potions, long long least){
        int l = 0;
        int h = potions.size() - 1;
        int inter = -1;

        while (l <= h) {
            int m = l + (h - l)/2;

            if (potions[m] >= least) {
                inter = m;
                h = m - 1;
            } else {
                l = m + 1;
            }
        }

        if (inter == -1) return 0;
        return (potions.size() - 1 - inter + 1);
    }
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end());
        vector<int> ans;

        for (auto s: spells) {
            long long q = success / s;
            if (success % s) q++;

            ans.push_back(bs(potions,q));

        }

        return ans;
    }
};