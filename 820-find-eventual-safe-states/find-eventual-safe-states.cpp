class Solution {
public:
    vector<int> ans;
    map<int,int> status;
    bool dfs(int index, vector<vector<int>>& graph){
        if (graph[index].size() == 0){
            status[index] = 1;
            return true;
        }

        status[index] = 0;

        bool allPaths = true;
        for (int i = 0 ; i < graph[index].size() ; i++){
            int next = graph[index][i];
            if (status.find(next) == status.end()) {
                allPaths = allPaths && dfs( next,graph);
                continue;
            }

            if (status[next] == 0 ){
                return false;
            } 
        }

        status[index] = allPaths;

        return allPaths;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int nodes = graph.size();
        for (int i = 0 ; i < nodes ; i++){
            dfs(i,graph);
        }

        for (auto &[key,val] : status){
            if (val == 1){
                ans.push_back(key);
            }
        }

        return ans;
    }
};