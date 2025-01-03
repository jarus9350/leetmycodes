class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {
        int n = nums.size();
        map<double,int> mp;
        double totalSum = 0;

        for (int i = 0 ; i < n ; i++){
            int n = nums[i];
            totalSum+= n;
            mp[n] = i;
        }

        int ans = INT_MIN;
        for (int i = 0 ; i < n ; i++){
            int n = nums[i];
            double m = ((double)(totalSum - n))/2;
            if (mp.find(m) != mp.end() && i != mp[m]) {
                // cout<<m<<" "<<n<<endl;
                ans = max(ans,n);
            }
        }
       
        return ans;
    }
};