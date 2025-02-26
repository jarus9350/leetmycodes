class Solution {
public:
    bool canJump(vector<int>& nums) {
        // int reachable = 0;
        
        // for (int i = 0 ; i < nums.size() ; i++){
        //     if (reachable < i){
        //         return false;
        //     }

        //     reachable = max(reachable, i + nums[i]);
        // }
    
        // return true;
        int n = nums.size();
        vector<int> canVisit(n,0);
        canVisit[n-1] = 1;

        for (int i = n - 2 ; i >= 0 ; i--){
            int jumps = nums[i];

            bool reachable = false;
            int currentIndex = i;

            for (int j = 1 ; j <= jumps ; j++){
                if (currentIndex + j < n && canVisit[currentIndex + j]){
                    reachable = true;
                    break;
                }
            }

            canVisit[i] = reachable;
        }

        return canVisit[0];


    }
};