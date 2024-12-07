class Solution {
public:
    bool possible(vector<int>& nums, int bins, int maxOperations, int val){
        // cout<<val<<endl;
        int operations = 0;
        for (int i = 0 ; i < nums.size() ; i++){
            int n = nums[i];

            if ( n > val){
                operations += ceil((double)(n)/val)-1;
            }
        }

        cout<<val<<" "<<operations<<endl;
        if (operations > bins) return false;
        // cout<<val<<endl;
        return true;
    }

    int minimumSize(vector<int>& nums, int maxOperations) {
        int maxNum = *max_element(nums.begin(),nums.end());
        int s = nums.size();

        int l = 1;
        int h = maxNum;

        // int bins = s + maxOperations;
        int bins = maxOperations;

        while (l <= h){
            int mid =  l + (h - l)/2;
            if (possible(nums,bins,maxOperations,mid)){
                h = mid-1;
            } else {
                l = mid+1;
            }
        }

        return l;

        
    }
};