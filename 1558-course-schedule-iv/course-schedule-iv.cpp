class Solution {
public:
    bool BFS(int c1, int c2,int& numCourses,vector<vector<int>>& graph){
        vector<bool> vis(numCourses,false);

        queue<int> q;
        q.push(c1);
        vis[c1] = true;

        while (!q.empty()){
            auto f = q.front();
            q.pop();

            if (f == c2) return true;

            // if (vis[f]) continue;

            for (auto n: graph[f]){
                if (!vis[n]) {
                    q.push(n);
                    vis[n] = true;
                } 
            }
        }

        return false;
    }
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {

        vector<vector<int>> graph(numCourses,vector<int>());
        vector<bool> ans;

        

        for (auto v: prerequisites){
            int from = v[0];
            int to = v[1];

            graph[from].push_back(to);
        }

        for (int i = 0 ; i < numCourses ; i++){
            cout<<i<<" : ";
            for (auto n: graph[i]){
                cout<<n<<" ";
            }
            cout<<endl;
        }

        for (auto q: queries){
            int c1 = q[0];
            int c2 = q[1];

            bool inter = BFS(c1,c2,numCourses,graph);
            ans.push_back(inter);

        }

        return ans;


    }
};