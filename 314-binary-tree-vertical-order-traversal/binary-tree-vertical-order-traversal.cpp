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

    vector<vector<int>> verticalOrder(TreeNode* root) {
        if (!root) return {};
        map<int,vector<int>> mp;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});

        while (!q.empty()){
            int levelSize = q.size();
            while (levelSize--){
                auto [node, vertical] = q.front();
                q.pop();

                mp[vertical].push_back(node->val);

                if (node->left) q.push({node->left, vertical - 1});
                if (node->right) q.push({node->right, vertical + 1});
            }
        }

        vector<vector<int>> ans;
        for (auto [key , vec] : mp){
            ans.push_back(vec);
        }

        return ans;
        
    }
};