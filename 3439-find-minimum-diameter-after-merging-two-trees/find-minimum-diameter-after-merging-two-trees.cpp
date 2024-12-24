class Solution {
public:
    pair<int,int> bfs(int start, vector<vector<int>>& adjList){

        queue<vector<int>> q;
        q.push({start,0,-1});
        int fartherstNode = -1;
        int deepestLevel = -1;

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

    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n1 = edges1.size() + 1;
        vector<vector<int>> adjList1(n1);

        for (auto e: edges1){
            int from = e[0];
            int to = e[1];

            adjList1[from].push_back(to);
            adjList1[to].push_back(from);
        }

        int n2 = edges2.size() + 1;
        vector<vector<int>> adjList2(n2);

        for (auto e: edges2){
            int from = e[0];
            int to = e[1];

            adjList2[from].push_back(to);
            adjList2[to].push_back(from);
        }

        //for Tree1
        auto [DL1a,FN1a] = bfs(0,adjList1);
        auto [DL2a,FN2a] = bfs(FN1a,adjList1);

        cout<<DL2a<<endl;

        //for Tree2
        auto [DL1b,FN1b] = bfs(0,adjList2);
        auto [DL2b,FN2b] = bfs(FN1b,adjList2);

        cout<<DL2b<<endl;

        //joined trees
        int joinedDiameter =  ((DL2a % 2) ? DL2a/2 + 1: DL2a/2 )+ ((DL2b % 2) ? DL2b/2 + 1: DL2b/2)  + 1;

        return max( joinedDiameter, max(DL2a,DL2b));
    }
};