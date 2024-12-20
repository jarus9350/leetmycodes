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

    // TreeNode* reverseOddLevels(TreeNode* root) {
        
    // }

    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<pair<TreeNode*,int>> q;

        q.push({root,0});

        int level = 0;
        while(q.size()){
            int levelSize = q.size();
            vector<int> levelVals;
            while (levelSize--){
                auto [node, level] = q.front();
                q.pop();
                if (node->left) levelVals.push_back(node->left->val);
                if (node->right) levelVals.push_back(node->right->val);
                if (node->left) q.push({node->left, level+1});
                if (node->right) q.push({node->right, level+1});
            }
            level++;

            levelSize = q.size();
            if (level % 2){
                for (int i = levelVals.size() - 1; i >= 0 ; i--){
                    auto [node , level] = q.front();
                    node->val = levelVals[i];
                    q.pop();
                    q.push({node,level});
                }
            }
            
        }

        return root;
        
    }

};