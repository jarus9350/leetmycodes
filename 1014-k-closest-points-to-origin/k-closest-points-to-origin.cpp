struct Compare {
    bool operator()( const vector<int>& a, const vector<int>& b) {
        return ( a[0]*a[0] + a[1]*a[1]  < b[0]*b[0] + b[1]*b[1]);
    }
};

class Solution {
public:

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;

        sort(points.begin(),points.end(), Compare());

        for (int i = 0 ; i < k ; i++){
            ans.push_back(points[i]);
        }

        return ans;
    }
};