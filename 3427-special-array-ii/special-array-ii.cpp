class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        //3 4 1 2 6
        int s = nums.size();
        vector<int> consecutiveOrder(s,1);



        for (int i = 1 ; i < s ; i++){
            if ((nums[i-1] % 2 ) == 0) {
                if ( (nums[i] % 2 ) == 1) {
                    consecutiveOrder[i] = 1 + consecutiveOrder[i-1];
                } 
            } else {
                if ( (nums[i] % 2 ) == 0) {
                    consecutiveOrder[i] = 1 + consecutiveOrder[i-1];
                } 
            }
        }

        // for (auto n: consecutiveOrder){
        //     cout<<n<<" ";
        // }
        // cout<<endl;

        vector<bool> ans;
        for (auto q: queries){
            int startIndex = q[0];
            int endIndex = q[1];

            // cout<<startIndex<<" "<<endIndex<<endl;
    
            // if ((consecutiveOrder[endIndex] - (startIndex - 1 >= 0 ? consecutiveOrder[startIndex-1] : 0)) == (endIndex  - startIndex + 1)) {
            //     ans.push_back(true);
            // } else {
            //     ans.push_back(false);
            // }

            if ((consecutiveOrder[endIndex] - consecutiveOrder[startIndex] + 1) == (endIndex  - startIndex + 1)) {
                ans.push_back(true);
            } else {
                ans.push_back(false);
            }
        }

        return ans;
        
    }
};