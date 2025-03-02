class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i = 0;
        int j = 0;
        int n = nums.size();

        cout<<n<<" "<<k<<endl;

        int ans = 0;

        int countZeroes = 0;

        // if (k >= n) return n;

        while (j < n){
            if (nums[j] == 0) {
                countZeroes++;
            }

            if (countZeroes <= k){
                ans = max(ans,j - i + 1);
            } else if (countZeroes > k) {
                while (countZeroes > k) {
                    if (nums[i] == 0) {
                        countZeroes--;
                    }
                    i++;

                    // cout<<i<<" "<<j<<" "<<countZeroes<<endl;
                }
            }

            // cout<<i<<" "<<j<<endl;

            j++;
        }

        return ans;
    }
};