class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();
        int ans = energy[n-1];
        for (int i = n - 1 ; i >= 0 ; i--){
            int inter = energy[i] + (( (i + k ) < n ) ? energy[i+k] : 0);
            ans = max(ans,inter);
            energy[i] = inter;
        }

        return ans;
        
    }
};

// 5 2 -10 -5 1
//   3   10    -5   1