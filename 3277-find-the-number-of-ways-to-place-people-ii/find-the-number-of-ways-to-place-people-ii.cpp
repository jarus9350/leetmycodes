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
            //auto topLeft = points[i];
            int y = INT_MIN;
            for (int j = i + 1 ; j < points.size() ; j++ ){
                //auto bottomRight = points[j];

                if (isTopLeft(points[i], points[j])){
                    if (points[i][1] >= y && points[j][1] <= y) {
                        continue;
                    } else {
                        ans++;
                        y = points[j][1];
                    }
                    
                } 
            }
        }
        
        return ans;
    }
};