class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        double ans = 0;
        for (int i = 0 ; i < points.size() - 2 ; i++){
            for (int j = i + 1 ; j < points.size() - 1 ; j++){
                for (int k = j + 1; k < points.size() ; k++){
                    double x1 = (double)points[i][0];
                    double y1 = (double)points[i][1];
                    double x2 = (double)points[j][0];
                    double y2 = (double)points[j][1];
                    double x3 = (double)points[k][0];
                    double y3 = (double)points[k][1];

                    double area = 0.5*abs(x1*y2 + x2*y3 + x3*y1 - y1*x2 - y2*x3 - y3*x1);
                    ans = max(ans,area);

                }
            }
        }

        return ans;
    }
};