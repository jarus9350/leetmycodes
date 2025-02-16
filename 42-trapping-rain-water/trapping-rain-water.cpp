class Solution {
public:
    int trap(vector<int>& height) {
        int len = height.size();
        int l = 0;
        int r = len - 1;

        int maxLeft = height[l];
        int maxRight = height[r];
        int ans = 0;

        while (l < r) {
            if (maxLeft <= maxRight){
                l++;
                maxLeft = max(maxLeft,height[l]);
                ans += maxLeft - height[l];
            } else {
                r--;
                maxRight = max(maxRight, height[r]);
                ans += maxRight - height[r];
            }
        }

        return ans;
        
    }
};