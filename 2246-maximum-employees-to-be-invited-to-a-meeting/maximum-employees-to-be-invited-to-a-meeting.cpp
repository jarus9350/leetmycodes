class Solution {
public:
    int BFS(int cur, int parent,vector<vector<int>>& inverted){
        int length = 0;

        queue<pair<int,int>> q;
        q.push({cur,0});

        while (!q.empty()){
            auto [cur, l] = q.front();
            q.pop();

            if (cur == parent) continue;
            
            length = max(l,length);

            for (auto neigh: inverted[cur]){
                q.push({neigh, l+1});
            }
        }

        return length;

    }

    int maximumInvitations(vector<int>& favorite) {
        int n = favorite.size();
        int maxLengthCycle = INT_MIN;
        //keeping track of length 2 cycles
        vector<pair<int,int>> length_2_cycles;

        // length of longest closed cycle
        vector<bool> vis(n,false);
        for (int i = 0 ; i < n ; i++){
            if (vis[i]) continue;

            int start = i;
            int cur = i;

            set<int> s;

            while (!vis[cur]){
                vis[cur] = true;
                s.insert(cur);
                cur = favorite[cur];
            }

            if ( s.find(cur) != s.end()){
                int length = s.size();
                while (start != cur){
                    length--;
                    start = favorite[start];
                }

                maxLengthCycle = max(maxLengthCycle,length);

                if (length == 2){
                    length_2_cycles.push_back({cur,favorite[cur]});
                }
            }
        }

        //inverted directions favorite
        vector<vector<int>> inverted(n,vector<int>());
        for (int i = 0 ; i < n ; i++){
            int start = i;
            int end = favorite[i];
            inverted[end].push_back(start);
        }

        // length of combined 2 pair cycles
        // changing directions
        int chain_sum = 0;
        for (auto [n1, n2]: length_2_cycles){
            chain_sum += BFS(n1,n2,inverted) + BFS(n2,n1,inverted) + 2;
        }

        cout<<chain_sum<<" "<<maxLengthCycle<<endl;
        return max(chain_sum,maxLengthCycle);
    }
};

//neetcode
// https://www.youtube.com/watch?v=aPBELJa-LM8