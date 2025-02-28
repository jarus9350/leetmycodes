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
        vector<int> ans;

        queue<TreeNode*> q;
        q.push(root);

        while (q.size()){
            int levelLength = q.size();
            ans.push_back(q.back()->val);
            while (levelLength--){
                auto front = q.front();
                q.pop();

                if (front->left) q.push(front->left);
                if (front->right) q.push(front->right);
            }
        }

        return ans;
        
    }
};