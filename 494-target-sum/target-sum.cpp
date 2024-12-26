class Solution {
public:
    int ans = 0;
    int totalPossibleWays(int i, vector<int>& nums, int target,int n, int sum){
        if (i == n){
            if (sum == target) ans++;
            return 0;
        } 
        
        totalPossibleWays(i+1, nums, target, n, sum + nums[i]);
        totalPossibleWays(i+1, nums, target, n, sum - nums[i]);
        return 0;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        totalPossibleWays(0, nums, target, nums.size(),0);
        return ans;
    }
};