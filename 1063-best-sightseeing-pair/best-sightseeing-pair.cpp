class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();
        int maxSum = INT_MIN;

        int previousMax = values[0] + 0;
        for (int i = 1 ; i < n ; i++){
            int currentVal = values[i] - i;
            maxSum = max(maxSum, previousMax + currentVal);
            previousMax = max(previousMax, values[i] + i);

        }

        return maxSum;
        /*
        int n = values.size();
        vector<vector<int>> v(2,vector<int>(n));
        for (int i = 0 ; i < n ; i++){
            v[0][i] = values[i] + i;
            v[1][i] = values[i] - i;
        }

        for (int i = 1 ; i < n ; i++){
            v[0][i] = max(v[0][i], v[0][i-1]);
        }

        for (int i = n- 2 ; i >= 0; i--){
            v[1][i] = max(v[1][i], v[1][i+1]);
        }

        int maxSum = INT_MIN;
        for (int i = 0 ; i < n ; i++){
            if (i + 1 < n ) maxSum = max(maxSum, v[0][i] + v[1][i+1]);
        }

        return maxSum;
        */
        
    }
};