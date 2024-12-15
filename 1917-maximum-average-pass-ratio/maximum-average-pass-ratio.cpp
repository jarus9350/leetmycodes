class Solution {
public:
    double diff(pair<int,int> a){
        int num = a.first;
        int denum = a.second;
        return (double)(num + 1)/(denum + 1) - (double)(num)/(denum);
    }

    double newVal(pair<int,int> a){
        int num = a.first;
        int denum = a.second;
        return (double)(num + 1)/(denum + 1);
    }

    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<double,pair<int,int>>> pq;

        for (int i = 0 ; i < classes.size() ; i++){
            auto cl = classes[i];
            int num = cl[0];
            int denum = cl[1];
            // double ratio = (double)(num)/denum;
            // pq.push({ratio,{num,denum}});
            pq.push({diff({num,denum}),{num,denum}});
        }

        double ans = 0;

        // while (pq.size()){
        //     cout<<pq.top().first<<endl;
        //     pq.pop();
        // }


        while (extraStudents--){
            auto [dif, indexes] = pq.top();
            pq.pop();

            int num = indexes.first;
            int denum = indexes.second;

            pq.push({ diff({num + 1, denum + 1}), {num + 1, denum + 1}});
            
            // pq.push({diff({num,denum}),{num,denum}});
        }

        while (pq.size()){
            // cout<<pq.top().first<<endl;
            auto [diff, indexes] = pq.top();
            ans += (double)(indexes.first)/(indexes.second);
            pq.pop();
        }

        // for (auto cl: classes){
        //     ans += (double)(cl[0])/cl[1];
        // }

        return ans/classes.size();

        
    }
};
