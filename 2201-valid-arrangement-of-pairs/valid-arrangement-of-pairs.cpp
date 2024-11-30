class Solution {
public:
    vector<int> result;
    void PostOrderDFS(unordered_map<int,deque<int>>& adj,int startNode){
        while (adj[startNode].size()){
            int nextNode = adj[startNode].front();
            adj[startNode].pop_front();
            PostOrderDFS(adj,nextNode);
        }
        result.push_back(startNode);
    }
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int,deque<int>> adj;
        unordered_map<int,int> order;

        for (auto p : pairs){
            int from = p[0];
            int to = p[1];

            order[from]++;
            order[to]--;

            adj[from].push_back(to);
        }

        vector<vector<int>> ans;

        int k = -1;
        for (auto &[key,value] : order){
            if (value == 0 && k == -1){
                k = key;
            }
            if (value > 0){
                k = key;
                break;
            }
            // cout<<key<<" "<<value<<endl;
        }

        PostOrderDFS(adj, k);

        reverse(result.begin(),result.end());

        // cout<<"r"<<result.size()<<endl;

        for(int i = 0 ; i < result.size() ; i++){
            if (i - 1 >=0 ) ans.push_back({result[i-1],result[i]});
        }

        

        // cout<<k<<endl;
        return ans;


        
    }
};