// class Node {
//     int val;
//     int index;
//     Node* left;
//     Node* right;

//     Node (int val, int index){
//         val = val;
//         index = index;
//         left = nullptr;
//         right = nullptr;
//     }

// };

class Solution {
private:
    int dfs(int curr, int parent, vector<int> adjList[],vector<int>& values,int& k,int& ans){
        int total = 0;

        for (auto& child : adjList[curr]){
            if (child != parent){
                total += dfs(child,curr,adjList,values,k,ans);
                total %= k;
            }
        }

        total += values[curr];
        total %= k;
        

        if (total == 0){
            ans++;
        }

        return total;
    }
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<int> adjList[n];

        for (auto e: edges){
            int from = e[0];
            int to = e[1];
            adjList[from].push_back(to);
            adjList[to].push_back(from);
        }    

        int ans = 0;

        dfs(0,-1,adjList,values,k,ans);

        return ans;   
    }
};