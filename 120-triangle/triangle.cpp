class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> prev = triangle[triangle.size() - 1];

        for (int i = triangle.size() - 2 ; i >= 0 ; i--){
            for (int j = 0  ; j <  triangle[i].size() ; j++){
                prev[j] = triangle[i][j] +  min(prev[j], prev[j+1]);
            }
        }

        return prev[0];
        
    }
};