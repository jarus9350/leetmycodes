class Solution {
public:
    long long minimumHealth(vector<int>& damage, int armor) {
        long long ans = 0;

        int maxi = INT_MIN;
        for (auto n: damage){
            maxi = max(maxi,n);
            ans += n;
        }

        if (maxi >= armor){
            ans -= armor;
        } else {
            ans -= maxi;
        }

        return ans + 1;
    }
};