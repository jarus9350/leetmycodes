class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {
        int n = nums.size();
        unordered_map<double,int> mp;
        double total = 0;

        for (auto n: nums){
            total += n;
            mp[(double)n]++;
        }

        int ans = INT_MIN;

        for (int i = 0 ; i < n ; i++){
            int num = nums[i];
            double remaining = (double)(total - num)/2;

            if (mp.find(remaining) != mp.end()) {
                mp[num]--; //considering

                int occ = mp[remaining];
                if (occ > 0) ans = max(ans,num);

                mp[num]++; //adding back
            }
        }

        return ans;


        
    }
};