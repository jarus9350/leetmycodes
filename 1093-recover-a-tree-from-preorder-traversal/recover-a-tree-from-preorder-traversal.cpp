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
    TreeNode* recoverFromPreorder(string traversal) {
        int dashes = 0;
        vector<TreeNode*> st;

        int i = 0;
        while (i < traversal.length()) {
            if (traversal[i] == '-'){
                dashes++;
                i++;
            } else {
                int j = i;
                string a = "";
                while (j < traversal.length() && traversal[j] != '-'){
                    a = a + traversal[j];
                    j++;
                }

                int num = stoi(a);
                // cout<<a<<" "<<num<<endl;

                TreeNode* n = new TreeNode(num);

                while (st.size() > dashes) { 
                    st.pop_back();
                }

                if (st.size() && st.back()->left == nullptr){
                    st.back()->left = n;
                } else if (st.size() ){
                    st.back()->right = n;
                }

                st.push_back(n);

                
                dashes = 0;


                i = j;
            }
        }

        return st[0];
        
        
    }
};