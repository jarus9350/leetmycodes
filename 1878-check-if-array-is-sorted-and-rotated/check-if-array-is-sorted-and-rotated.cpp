class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();

        int index = 0;
        for (int i = 1; i < n ; i++){
            if (nums[i-1] > nums[i]){
                index = i;
                break;
            }
        }

        for (int i = 1 ; i < index ; i++){
            if (nums[i-1] > nums[i]) return false;
        }

        for (int i = index + 1 ; i < n ; i++){
            if (nums[i-1] > nums[i]) return false;
        }

        int last = nums[n-1];

        for (int i = 0 ; i < index ; i++){
            if (nums[i] < last) return false;
        }

        return true;
    }
};