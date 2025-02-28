class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int prev = nums[0];

        int j = 1;
        for (int i = 1; i < n ; i++){
            int curr = nums[i];
            if (curr == prev) { 
            } else {
                prev = nums[i];
                swap(nums[i],nums[j]);
                j++;
            }
        }

        // cout<<j<<endl;

        // for (auto c: nums){
        //     cout<<c<<" ";
        // }
        // cout<<endl;

        return j;


        //1 1 1 1 2 2 3 3 4 5
        
    }
};