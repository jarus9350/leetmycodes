struct Compare {
    bool operator() (const vector<int>& a, const vector<int>& b){
        if (a[0] == b[0]){
            return a[1] > b[1];
        }

        return a[0] < b[0];
    }
};
class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<vector<int>> yearsPolarity;

        for (auto l: logs){
            yearsPolarity.push_back({l[0],0});
            yearsPolarity.push_back({l[1],1});
        }

        sort(yearsPolarity.begin(),yearsPolarity.end(), Compare());

        // for (auto yp: yearsPolarity){
        //     cout<<yp[0]<<" "<<yp[1]<<endl;
        // }

        int currentPopulation = 0;
        int maxPopYear = INT_MAX;
        int maxPopulation = INT_MIN;

        for (auto yP : yearsPolarity){
            int year = yP[0];
            int polarity = yP[1];

            if (!polarity){
                currentPopulation++;
                if (currentPopulation > maxPopulation){
                    maxPopulation = currentPopulation;
                    maxPopYear = year;
                }
            } else {
                currentPopulation--;
            }   
        }

        // cout<<"mp "<<maxPopulation<<endl;

        return maxPopYear;
        
    }
};