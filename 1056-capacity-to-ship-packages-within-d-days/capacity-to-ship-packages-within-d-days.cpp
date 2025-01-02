class Solution {
public:
    int possible(vector<int>& weights, int days, int maxWeight){
        int totalDays = 1;
        int sum = 0;
        for (int i = 0 ; i < weights.size() ; i++){
            sum += weights[i];
            if (sum > maxWeight){
                totalDays++;
                sum = weights[i];
            }
        }

        // if (sum > maxWeight) totalDays++;

        // cout<<totalDays<<" "<<maxWeight<<endl;

        return totalDays <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {        
        int totalWeight = 0;
        int l = INT_MIN;
        for (auto w: weights)  {
            totalWeight += w;
            l = max(l,w);
        }

        int h = totalWeight;
        int ans = INT_MAX;

        while (l <= h){
            int m = l + (h - l)/2;
            if (possible(weights,days,m)) {
                // cout<<"possible "<<m<<endl;
                ans = min(ans,m);
                h = m - 1;
            } else {
                l = m + 1;
            }
        }

        return ans;
    }
};