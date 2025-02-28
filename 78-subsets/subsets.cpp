class Solution {
public:
    void dfs(int i,int& n,vector<vector<int>>& ans,vector<int>& nums,vector<int>& inter){
        if (i == n) {
            ans.push_back(inter);
            return;
        }

        //include
        inter.push_back(nums[i]);
        dfs(i+1,n,ans,nums,inter);
        
        inter.pop_back();
        //exclude
        dfs(i+1,n,ans,nums,inter);
        return;

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> inter = {};
        dfs(0,n,ans,nums,inter);
        return ans;
    }
};