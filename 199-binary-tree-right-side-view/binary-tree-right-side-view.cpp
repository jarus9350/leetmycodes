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
    vector<int> rightSideView(TreeNode* root) {
        if (root == nullptr) return {};
        queue<TreeNode*> q;
        vector<int> ans;
        q.push(root);

        int level = 1;
        while (q.size()){
            int levelSize = q.size();
            while (levelSize--){
                auto front = q.front();
                q.pop();

                if (ans.size() < level){
                    ans.push_back(front->val);
                } else {
                    ans[level-1] = front->val;
                }
                

                if (front->left) q.push(front->left);
                if (front->right) q.push(front->right);
    
            }

            level++;
        }
        

        return ans;
    }
};