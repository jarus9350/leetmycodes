class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0;
        int h = height.size() - 1;

        int ans = 0;
        while (l <= h) {
            int waterContained = min(height[l],height[h])*(h - l);
            ans = max(ans,waterContained);

            if (height[l] < height[h]){
                l++; 
            } else {
                h--;
            }
        }
        
        return ans;
    }
};