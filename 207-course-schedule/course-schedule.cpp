class Solution {
public:
    bool dfs(int i, vector<int>& vis, unordered_map<int,vector<int>>& adjList){
        if (adjList[i].size() == 0) return true;
        if (vis[i]) return false;

        vis[i] = 1;

        for (auto pre: adjList[i]){
            bool ans = dfs(pre,vis,adjList);
            if (!ans) return false;
            
        }

        vis[i] = 0;
        adjList[i] = vector<int>();
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>> adjList;
        // for (int i = 0 ; i < numCourses ; i++) adjList[i] = vector<int>();
        
        vector<int> vis(numCourses,0);
        
        for (auto a : prerequisites){
            int to = a[0];
            int from = a[1];
            adjList[to].push_back(from);
        }

        for (int i = 0 ; i < numCourses; i++){
            if (!vis[i]){
                bool ans = dfs(i,vis,adjList);
                if (!ans)  return false;
            }
        }

        return true;
    }
};