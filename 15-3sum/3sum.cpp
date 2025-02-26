class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;

        for (int i = 0 ; i < n - 2; i++){
            int rem = -nums[i];
            int j = i + 1;
            int k = n - 1;

            while ( j < k ){
                int sum = nums[j] + nums[k];
                if (rem == sum){
                    ans.push_back({nums[i],nums[j],nums[k]});
                    j++;
                    k--;

                    while (j < k && nums[j-1] == nums[j]) j++;
                    while (j < k && nums[k] == nums[k+1]) k--;
                } else if (rem > sum) {
                    j++;
                } else if (rem < sum){
                    k--;
                } 
            }

            while (i + 1 < n && nums[i] == nums[i + 1]) i++;
        }

        return ans;
    }
};