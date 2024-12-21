// // class Node {
// //     int val;
// //     int index;
// //     Node* left;
// //     Node* right;

// //     Node (int val, int index){
// //         val = val;
// //         index = index;
// //         left = nullptr;
// //         right = nullptr;
// //     }

// // };

// class Solution {
// private:
//     // int ans = 0;
//     int dfs(int& curr, int& parent, vector<vector<int>> adjList,vector<int>& values,int& k,int& ans){
//         int total = values[curr];

//         for (auto& child : adjList[curr]){
//             if (child != parent){
//                 total += dfs(child,curr,adjList,values,k,ans);
//                 total %= k;
//             }
//         }

//         if (total % k == 0){
//             ans++;
//         }

//         return total;
//     }
// public:
//     int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
//         vector<vector<int>> adjList(n);

//         for (auto e: edges){
//             int from = e[0];
//             int to = e[1];
//             adjList[from].push_back(to);
//             adjList[to].push_back(from);
//         }    

//         int start = 0;
//         int parent = -1;
//         int ans = 0;

//         dfs(start,parent,adjList,values,k,ans);

//         return ans;   
//     }
// };

class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>> &edges,
                                vector<int> &values, int k) {
        // Step 1: Create adjacency list from edges
        vector<int> adjList[n];
        for (auto edge : edges) {
            int node1 = edge[0];
            int node2 = edge[1];
            adjList[node1].push_back(node2);
            adjList[node2].push_back(node1);
        }
        // Step 2: Initialize component count
        int componentCount = 0;

        // Step 3: Start DFS traversal from node 0
        dfs(0, -1, adjList, values, k, componentCount);

        // Step 4: Return the total number of components
        return componentCount;
    }

private:
    int dfs(int currentNode, int parentNode, vector<int> adjList[],
            vector<int> &nodeValues, int k, int &componentCount) {
        // Step 1: Initialize sum for the current subtree
        int sum = 0;

        // Step 2: Traverse all neighbors
        for (auto neighborNode : adjList[currentNode]) {
            if (neighborNode != parentNode) {
                // Recursive call to process the subtree rooted at the neighbor
                sum += dfs(neighborNode, currentNode, adjList, nodeValues, k,
                           componentCount);
                sum %= k;  // Ensure the sum stays within bounds
            }
        }

        // Step 3: Add the value of the current node to the sum
        sum += nodeValues[currentNode];

        // Step 4: Check if the sum is divisible by k
        sum %= k;
        if (sum == 0) componentCount++;

        // Step 5: Return the computed sum for the current subtree
        return sum;
    }
};