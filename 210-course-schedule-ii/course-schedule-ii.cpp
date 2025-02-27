class Solution {
public:
    bool dfs(int i,unordered_set<int>& cycle,unordered_set<int>& visited,int& numCourses,vector<vector<int>>& adjList,vector<int>& result){
        if (cycle.find(i) != cycle.end()) return false;
        if (visited.find(i) != visited.end()) return true;


        cycle.insert(i);
        for (auto pre: adjList[i]){
            if (!dfs(pre,cycle,visited,numCourses,adjList,result)) {
                return false;
            }
        }
        cycle.erase(i);
        visited.insert(i);
        result.push_back(i);

        return true;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_set<int> cycle, visited;
        vector<int> result;

        vector<vector<int>> adjList(numCourses,vector<int>());
        for (auto pre: prerequisites){
            int to = pre[0];
            int from = pre[1];
            adjList[to].push_back(from);
        }

        for (int i = 0 ; i < numCourses ; i++){
            if (dfs(i,cycle,visited,numCourses,adjList,result) == false) {
                return {};
            }
        }

        return result;


        
    }
};