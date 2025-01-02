class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double,vector<int>>, vector<pair<double,vector<int>>>, greater<pair<double,vector<int>>>> pq;
        vector<vector<int>> ans;

        for (auto p: points){
            int x = p[0];
            int y = p[1];
            double distance = sqrt(x*x + y*y);
            pq.push({distance,p});
        }

        while (k--){
            auto [distance, point] = pq.top();
            pq.pop();

            ans.push_back(point);
        }

        return ans;
    }
};