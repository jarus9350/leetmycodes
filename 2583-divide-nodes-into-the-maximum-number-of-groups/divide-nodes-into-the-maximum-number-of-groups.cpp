class Solution {
public:
    vector<vector<int>> adjList;
    vector<int> vis;
    set<int> getConnectedComponents(int src){
        set<int> s;

        queue<int> q;
        q.push(src);
        s.insert(src);

        while (q.size()){
            auto node = q.front();
            q.pop();

            for (auto n: adjList[node]){
                if (s.find(n) == s.end()){
                    s.insert(n);
                    q.push(n);
                    vis[n] = 1;
                }
            }
        }


        return s;
    }

    int maxLevel(int src){
        map<int,int> mp;

        queue<pair<int,int>> q;
        q.push({src,1});
        mp[src] = 1;

        int maxLevel = 1;

        while (q.size()){
            auto [node,level] = q.front();
            q.pop();

            maxLevel = max(maxLevel,level);

            for (auto n: adjList[node]){
                if (mp.find(n) != mp.end()){
                    if (mp[n] == level) return -1;
                    continue;
                } 

                q.push({n,level+1});
                mp[n] = level + 1;
            }
        }

        return maxLevel;

    }

    int magnificentSets(int n, vector<vector<int>>& edges) {
        adjList.resize(n+1,vector<int>());
        vis.resize(n+1,0);

        for (auto e: edges){
            int from = e[0];
            int to = e[1];
            adjList[from].push_back(to);
            adjList[to].push_back(from);
        }

        
        int ans = 0;

        for (int i = 1; i < n+1 ; i++){
            if (!vis[i]){
                vis[i] = 1;

                auto components = getConnectedComponents(i);

                int max_cnt = 0;
                for (auto n: components){
                    int cnt = maxLevel(n);
                    if (cnt == -1) return -1;
                    max_cnt = max(cnt,max_cnt);

                }

                ans += max_cnt;
            }
        }


        return ans;
        
    }
};