class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int i = 0;
        int j = 0;
        int n = blocks.size();

        int countW = 0;
        int ans = INT_MAX;
        while ( j < n ) {
            if (blocks[j] == 'W') countW++;

            if (j - i + 1 == k) {
                ans = min(ans,countW);
            } else if (j - i + 1 > k ){
                while (j - i + 1 > k) {
                    if (blocks[i] == 'W') {
                        countW--;
                    }
                    i++;
                }

                if (j - i + 1 == k) {
                    ans = min(ans,countW);
                }
            }

            j++;

        }

        return ans;
        
    }
};