/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        if (!root) return {};
        map<int,int> mp;
        queue<pair<TreeNode*,int>> q;
        vector<int> ans(10000,INT_MIN);

        if (root) q.push({root,0});
        int levels = 0;

        while (q.size()){
            int levelSize = q.size();
            while (levelSize--){
                auto [node, level] = q.front();
                q.pop();

                // mp[level] = max(mp[level],node->val);
                ans[level] = max(ans[level],node->val);
                levels = max(levels,level);

                if (node->left) q.push({node->left, level+1});
                if (node->right) q.push({node->right, level+1});

            }
        }

        // for (auto m: mp){
        //     ans.push_back(m.second);
        // }
        vector<int> newAns(levels+1);
        for (int i = 0 ; i <= levels ; i++){
            newAns[i] = ans[i];
        }
        
        return newAns;
    }
};