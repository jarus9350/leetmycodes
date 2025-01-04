/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* adjListBuilder(TreeNode* root, vector<vector<int>>& adjList){
        if (!root) return nullptr;

        if (root->left) adjList[root->val].push_back(root->left->val);
        if (root->right) adjList[root->val].push_back(root->right->val);

        auto left = adjListBuilder(root->left,adjList);
        auto right = adjListBuilder(root->right,adjList);

        if (left) {
            adjList[left->val].push_back(root->val);
        }

        if (right) {
            adjList[right->val].push_back(root->val);
        }

        return root;

    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<vector<int>> adjList(500);
        adjListBuilder(root,adjList);

        // for ( int i = 0 ; i < 500 ; i++){
        //     cout<<i<<" | ";
        //     for (auto n: adjList[i]){
        //         cout<<n<<" ";
        //     }
        //     cout<<endl;
        // }

        queue<vector<int>> q;
        q.push({target->val,0,-1}); // val , level , parent

        vector<int> ans;

        while (!q.empty()){
            int levelSize = q.size();
            bool toBreak = false;
            while (levelSize--){
                auto front = q.front();

                int val = front[0];
                int level = front[1];
                int parent = front[2];

                if ( level > k) {
                    toBreak = true;
                    break;
                }

                q.pop();

                if (level == k){
                    ans.push_back(val);
                }

                for (auto n: adjList[val]){
                    // cout<<n<<" oye yahan pe aaya kya"<<endl;
                    if (n != parent){
                        q.push({n,level+1,val});
                    }
                }
            }

            if (toBreak) break;
        }

        return ans;




    }
};