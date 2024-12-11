class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int i = 0;
        int j = 0;

        int ans = 0;

        while (j < n){
            
            if (nums[j] - nums[i] <= 2*k){
                ans = max(ans, j - i + 1);
                cout<<i<<" "<<j<<" "<<ans<<endl;
            } else {
                while ( j >= i && nums[j] - nums[i] > 2*k){
                    i++;
                }
            }

            j++;
        }

        return ans;
        
    }
};