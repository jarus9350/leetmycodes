class Solution {
public:
    vector<vector<int>> ans;
    void backtrack(vector<int>& candidates,int target,int index,int n,vector<int>& inter){
        if (index == n) return;
        if (target < 0) return;

        if (target == 0){
            ans.push_back(inter);
            return;
        }

        //include
        inter.push_back(candidates[index]);
        backtrack(candidates, target - candidates[index], index, n, inter);
        inter.pop_back();

        //exclude
        backtrack(candidates, target, index+1, n, inter);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<int> inter;
        backtrack(candidates, target, 0, n,inter);
        return ans;
    }
};