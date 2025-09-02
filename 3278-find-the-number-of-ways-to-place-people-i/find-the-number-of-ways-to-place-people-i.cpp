class Solution {
public:
    static bool comp(vector<int>& a, vector<int>& b){
        if (a[0] != b[0]) return a[0] < b[0];
        return a[1] > b[1];
    }

    bool isTopLeft(vector<int>& a, vector<int>& b){
        return  (a[0] <= b[0] && a[1] >= b[1]);
    }

    bool isBetween(vector<int>& a,vector<int>& mid, vector<int>& b){
        return ( mid[0] >= a[0] && mid[0] <= b[0]) && (mid[1] >= b[1] && mid[1] <= a[1]);
    }

    int numberOfPairs(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), comp);
        for (auto a: points){
            cout<< a[0] <<" "<<a[1]<<endl;
        }
        int ans = 0;
        for(int i = 0 ; i < points.size() ; i++){
            for (int j = i + 1 ; j < points.size() ; j++ ){
                auto topLeft = points[i];
                auto bottomRight = points[j];

                if (isTopLeft(topLeft, bottomRight)){

                    if (j - i > 1) {
                        bool found = true;
                        for (int k = i + 1 ; k <= j - 1 ; k++){
                            auto point = points[k];
                            if (isBetween(topLeft, point, bottomRight)){
                                found = false;
                                break;
                            }
                        }

                        if (found) ans++;
                    } else if (j - i == 1) {
                        ans++;
                    }
                } 
            }
        }
        
        return ans;
    }
};