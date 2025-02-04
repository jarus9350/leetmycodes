class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int h = 0;
        int maxSum = 0;

        int sum = 0;
        while (h < n){
            sum += nums[h];

            if ( h - 1 >= 0 && nums[h] > nums[h-1]) {
                maxSum = max(maxSum,sum);
            } else {
                // cout<<"h "<<h<<endl;
                l = h;
                sum = nums[h];
                maxSum = max(maxSum,sum);
            }

            h++;
        }

        return maxSum;
    }
};