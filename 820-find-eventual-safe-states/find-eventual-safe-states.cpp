class Solution {
public:
    vector<int> ans;
    map<int,int> status;
    bool dfs(int startingIndex, int index, vector<vector<int>>& graph, vector<int> vis){
        if (graph[index].size() == 0){
            status[index] = 1;
            return true;
        }

        status[index] = 0;

        bool allPaths = true;
        for (int i = 0 ; i < graph[index].size() ; i++){
            int next = graph[index][i];
            if (status.find(next) == status.end()) {
                allPaths = allPaths && dfs(startingIndex, next,graph,vis);
            }

            if (status[next] == 0 ){ // already in map
                // allPaths = allPaths && false;
                return false;
            } 
        }

        status[index] = allPaths;

        return allPaths;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int nodes = graph.size();
        vector<int> vis(nodes, 0);
        for (int i = 0 ; i < nodes ; i++){
            dfs(i,i,graph,vis);
        }

        for (auto [key,val] : status){
            if (val == 1){
                ans.push_back(key);
            }
        }

        return ans;
    }
};