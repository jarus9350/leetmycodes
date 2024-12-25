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
        queue<pair<TreeNode*,int>> q;
        vector<int> ans(10000,INT_MIN);
        vector<int> newSomething;

        if (root) q.push({root,0});
        int levels = 0;

        while (q.size()){
            int levelSize = q.size();
            while (levelSize--){
                auto [node, level] = q.front();
                q.pop();

                if (newSomething.size() < level + 1){
                    newSomething.push_back(node->val);
                } else {
                    newSomething[level] = max(newSomething[level],node->val);
                }

                ans[level] = max(ans[level],node->val);
                levels = level;

                if (node->left) q.push({node->left, level+1});
                if (node->right) q.push({node->right, level+1});

            }
        }

        vector<int> newAns(levels+1);
        for (int i = 0 ; i <= levels ; i++){
            newAns[i] = ans[i];
        }
        
        // return newAns;

        return newSomething;


    }
};