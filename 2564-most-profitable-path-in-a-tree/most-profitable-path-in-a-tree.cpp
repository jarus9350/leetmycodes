class Solution {
public:
    int BFS(int src,vector<vector<int>>& adjList,unordered_map<int,int>& bobNodeIndex,vector<int>& amount) {
        int ans = INT_MIN;
        queue<vector<int>> q;
        q.push({src,-1,0,0});

        while (q.size()) {
            auto front = q.front();
            q.pop();

            int s = front[0];
            int p = front[1];
            int t = front[2];
            int c = front[3];

            if (bobNodeIndex.find(s) != bobNodeIndex.end()){
                int time = bobNodeIndex[s];
                if (time < t){
                    c += 0;
                } else if (time == t){
                    c += amount[s]/2;
                } else if (time > t){
                    c += amount[s];
                }
            } else {
                c += amount[s];
            }

            if (adjList[s].size() == 1 && adjList[s][0] == p) {
                ans = max(ans,c);
            }

            for (auto n : adjList[s]){
                if (p != n){
                    q.push({n,s,t+1,c});
                }
            }
        }

        return ans;
    }
    bool DFS(int src,int parent,int destination,int time,unordered_map<int,int>& bobNodeIndex,vector<vector<int>>& adjList){
        if (src == destination) {
            bobNodeIndex[src] = time;
            return true;
        } 

        // if (adjList[src].size() == 1 && adjList[src][0] == parent) return false;
        if (adjList[src].size() == 0) return false;

        bool inter = false;
        for (auto n: adjList[src]){
            if (parent != n) {
                inter = inter || DFS(n,src,destination,time+1,bobNodeIndex,adjList);
            }
        }

        if (inter) bobNodeIndex[src] = time;

        return inter;

    }
    

    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = amount.size();
        vector<vector<int>> adjList(n,vector<int>());

        for (auto edge : edges){
            int to = edge[0];
            int from = edge[1];

            adjList[to].push_back(from);
            adjList[from].push_back(to);
        }

        unordered_map<int,int> bobNodeIndex;

        DFS(bob,-1,0,0,bobNodeIndex,adjList);

        // cout<<bobNodeIndex.size()<<endl;
        // for (auto [key,value]: bobNodeIndex){
        //     cout<<key<<" "<<value<<endl;
        // }
        int ans = 0;
        ans = BFS(0,adjList,bobNodeIndex,amount);


        return ans;        
    }
};