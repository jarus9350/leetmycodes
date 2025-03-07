class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        // all negatives to zero
        for (int i = 0 ; i < n ; i++) { 
            if ( nums[i] < 0 ){
                nums[i] = 0;
            }
        }

        int defaultValue = -(n + 1); //it will not be in array

        for (int i = 0 ; i < n ; i++) {
            int num = nums[i];
            int index = abs(num) - 1;

            if (index >= 0 && index < n) {
                int numAtIndex = nums[index];

                if (numAtIndex == 0) {
                    nums[index] = defaultValue;
                } else {
                    if (numAtIndex < 0) {
                        // continue;
                    } else {
                        nums[index] = -nums[index];
                    }
                }
            }            
        }

        // for (auto n: nums){
        //     cout<<n<<" ";
        // }
        // cout<<endl;

        for (int i = 1 ; i <= n ; i++) {
            // if (nums[i-1] < 0 || nums[i-1] == defaultValue)  {
            //     continue;
            // } else {
            //     return i;
            // }

            if (nums[i-1] >= 0 && nums[i-1] != defaultValue) return i;
        }


        return n+1;

        
    }
};