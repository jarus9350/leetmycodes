class Solution {
public:

    static bool comp(const vector<int>& a,const vector<int>& b){
        if (a[0] != b[0]) return a[0] < b[0];
        return a[1] > b[1];
    }

    bool isTopLeft(const vector<int>& a,const vector<int>& b){
        return  (a[0] <= b[0] && a[1] >= b[1]);
    }

    int numberOfPairs(vector<vector<int>>& points) {
        // cout<<points.size()<<endl;
        sort(points.begin(), points.end(), comp);
        int ans = 0;
        for(int i = 0 ; i < points.size() ; i++){
            auto& topLeft = points[i];
            int y = INT_MIN;
            for (int j = i + 1 ; j < points.size() ; j++ ){
                auto& bottomRight = points[j];

                if (isTopLeft(topLeft, bottomRight)){
                    if (topLeft[1] >= y && bottomRight[1] <= y) {
                        
                    } else {
                        ans++;
                        y = bottomRight[1];
                    }
                    
                } 
            }
        }
        
        return ans;
    }
};