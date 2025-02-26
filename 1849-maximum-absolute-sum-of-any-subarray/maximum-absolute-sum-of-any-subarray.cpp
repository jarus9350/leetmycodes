class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int positiveSum = 0;
        int negativeSum = 0;

        int ansP = INT_MIN;
        int ansN = INT_MAX;

        for (auto n: nums){
            positiveSum += n;

            ansP = max(ansP,positiveSum);

            if (positiveSum < 0) {
                positiveSum = 0;
            }

            
        }

        for (auto n: nums){
            negativeSum += n;

            ansN = min(ansN,negativeSum);

            if (negativeSum > 0) {
                negativeSum = 0;
            }

            
        }

        cout<<ansP<<" "<<ansN<<endl;

        return max(abs(ansN),abs(ansP));
        
    }
};