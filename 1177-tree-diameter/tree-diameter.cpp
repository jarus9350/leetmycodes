class Solution {
public:
    pair<int,int> bfs(int start, vector<vector<int>>& adjList, int n){

        queue<vector<int>> q;
        q.push({start,1,-1});
        int fartherstNode = -1;
        int deepestLevel = 0;

        while (q.size()){
            int levelSize = q.size();

            while (levelSize--){
                auto front = q.front();
                int node = front[0];
                int level = front[1];
                int parent = front[2];

                if (level > deepestLevel){
                    deepestLevel = level;
                    fartherstNode = node;
                }

                q.pop();

                for (auto child : adjList[node]){
                    if (child != parent){
                        q.push({child,level+1,node});
                    }
                }
            }
        }

        return {deepestLevel,fartherstNode};
    }

    // int dfs(int node, int parent, vector<vector<int>>& adjList, int n){
    //     if ()
    // }
    int treeDiameter(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<vector<int>> adjList(n);

        for (auto e: edges){
            int from = e[0];
            int to = e[1];

            adjList[from].push_back(to);
            adjList[to].push_back(from);
        }

        auto [deepestLevel , fartherstNode] = bfs(0,adjList,n);
        auto [newDL, newFN] = bfs(fartherstNode,adjList,n);

        cout<<newDL<<" "<<newFN<<endl;

        return newDL-1;

        
    }
};