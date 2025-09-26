class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        if (nums.size() == 1) return 0;
        sort(nums.begin(),nums.end());

        int count = 0;

        for (int i = 0 ; i < nums.size() - 2 ; i++){
            int a = nums[i];
            if (a == 0) continue;
            for (int j = i+1 ; j < nums.size() - 1; j++) {
                int b = nums[j];
                if (b == 0) continue;

                int l = i + 1;
                int h = nums.size() - 1;

                int index = -1;
                while (l <= h ) {
                    int mid = l + (h - l)/2;
                    if (nums[mid] >= a + b) {
                        h = mid - 1;                       
                    } else if (nums[mid] < a + b) {
                        l = mid + 1;
                        index = l;
                    }
                }

                if (index != -1) count += index - j - 1;

            }
        }

        return count;
        
    }
};