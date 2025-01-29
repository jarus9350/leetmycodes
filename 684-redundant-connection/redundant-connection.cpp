class Solution {
public:
    //finds parent and path compression
    int find(int n,vector<int>& parent){
        if (n == parent[n]){
            return parent[n];
        }
        parent[n] = find(parent[n],parent);
        return parent[n];
    }

    bool uni(int n1,int n2,vector<int>& parent,vector<int>& rank){
        int p1 = find(n1,parent);
        int p2 = find(n2,parent);

        if (p1 == p2){
            return false;
        }

        if (rank[p1] >= rank[p2]){
            parent[p2] = p1;
            rank[p1] += rank[p2];
        } else {
            parent[p1] = p2;
            rank[p2] += rank[p1];
        }

        return true;

    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        vector<int> parent(n+1,0);
        for (int i = 0 ; i < n + 1 ; i++) parent[i] = i;

        vector<int> rank(n+1,1);

        for (auto e: edges){
            int from = e[0];
            int to = e[1];

            if (!uni(from,to,parent,rank)) {
                return e;
            }
        }

        return {};
    }
};

// https://www.youtube.com/watch?v=1lNK80tOTfc