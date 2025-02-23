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
    TreeNode* recur(int i1,int i2, int j1,int j2, vector<int>& preorder,unordered_map<int,int>& numToIndex){
        if (i1 > i2 || j1 > j2) return nullptr;

        TreeNode* root = new TreeNode(preorder[i1]);

        if (i1 != i2) {
            int nextRoot = preorder[i1+1];
            int mid = numToIndex[nextRoot];
            int size = mid - j1 + 1;
            root->left = recur(i1+1,i1 + size,j1,mid,preorder,numToIndex);
            root->right = recur(i1 + size + 1, i2, mid+1, j2-1, preorder, numToIndex);
        }

        return root;

    }

    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        unordered_map<int,int> numToIndex;
        int len = preorder.size();
        for (int i = 0 ; i < postorder.size() ; i++){
            numToIndex[postorder[i]] = i;
        }

        return recur(0,len-1,0,len-1,preorder,numToIndex);



        
    }
};