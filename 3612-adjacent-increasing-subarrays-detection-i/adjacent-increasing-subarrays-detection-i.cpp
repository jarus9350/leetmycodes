class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        if (k == 1 ) return true;

        int n = nums.size();
        vector<int> tillI(n,1);
        vector<int> fromI(n,1);

        for (int i = 0 ; i < n ; i++){
            if ( i - 1 >= 0 && nums[i] > nums[i-1] ) tillI[i] += tillI[i-1];
        }

        for (int i = n - 1 ; i>= 0 ; i--){
            if ( i + 1 < n && nums[i] < nums[i+1]) fromI[i] += fromI[i+1];
        }

        // for (auto c: tillI){
        //     cout<<c<<" ";
        // }
        // cout<<endl;

        // for (auto c: fromI){
        //     cout<<c<<" ";
        // }
        // cout<<endl;

        for (int i = 0 ; i < n ; i++){
            if (  i+ 1 < n && tillI[i] >= k && fromI[i+1] >=k ) return true;
        }

        return 0;
        
    }
};