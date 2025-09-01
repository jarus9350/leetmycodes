class Solution {
public:
    // priority_queue<pair<double,int>, vector<pair<double,int>>, greater<pair<int,int>>> pq;

    priority_queue<pair<double,int>> pq;
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        for (int i = 0; i < classes.size() ; i++){
            double ratioChange = (double)(classes[i][0]+1)/(classes[i][1]+1) - (double)classes[i][0]/classes[i][1];
            pq.push({ratioChange,i});
        }

        while (extraStudents--){
            auto top = pq.top();
            pq.pop();

            double maxChange = top.first;
            int index = top.second;

            classes[index][0] += 1;
            classes[index][1] += 1;

            double newChange = (double)(classes[index][0]+1)/(classes[index][1]+1) - (double)classes[index][0]/classes[index][1];

            pq.push({newChange, index});
        }

        double ans = 0;
        while (pq.size()){
            auto top = pq.top();
            pq.pop();

            int index = top.second;

            ans += (double)classes[index][0]/classes[index][1]; 
        }

        return ans/classes.size();
   
    }
};