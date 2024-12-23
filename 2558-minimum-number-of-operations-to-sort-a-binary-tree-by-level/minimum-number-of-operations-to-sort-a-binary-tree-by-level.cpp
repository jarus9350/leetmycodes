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
    int findMinSwaps(vector<int>& levelvals){
        int swaps = 0;
        unordered_map<int, int> mp;

        for (int i = 0 ; i < levelvals.size() ; i++){
            mp[levelvals[i]] = i;
        }


        auto sortedLevelsVals = levelvals;
        sort(sortedLevelsVals.begin(),sortedLevelsVals.end());

        // for (auto l: levelvals){
        //     cout<<l<<" ";
        // }
        // cout<<endl;

        // for (auto l: sortedLevelsVals){
        //     cout<<l<<" ";
        // }
        // cout<<endl;

        for (int i = 0 ; i < levelvals.size() ; ){
            if (sortedLevelsVals[i] != levelvals[i]){
                int swapIndex = mp[sortedLevelsVals[i]];
                swap(sortedLevelsVals[i],sortedLevelsVals[swapIndex]);
                swaps++;
            } else {
                i++;
            }
        }

        return swaps;
    }

    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        int ans = 0;

        while(q.size()){
            int levelSize = q.size();
            vector<int> levelVals;
            while (levelSize--){
                auto node = q.front();
                q.pop();
                
                levelVals.push_back(node->val);

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);

            }

            ans += findMinSwaps(levelVals);

        }

        return ans;
        
    }
};
