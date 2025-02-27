class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> productLeft(n);
        vector<int> productRight(n);
        
        int productL = 1;
        int productR = 1;

        vector<int> ans(n,1);

        for (int i = 0 ; i < n ; i++){
            int num = nums[i];
            productL = productL*num;
            productLeft[i] = (productL);
        }

        for (int i = n - 1 ; i >= 0 ; i--){
            int num = nums[i];
            productR = productR*num;
            productRight[i] = (productR);
        }

        for (int i = 0 ; i < n ; i++){
            ans[i] = (i - 1 >= 0 ? productLeft[i-1] : 1) * (i + 1 < n ? productRight[i+1] : 1);
        }

        return ans;
        
    }
};