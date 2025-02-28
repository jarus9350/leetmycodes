class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0;
        int j = 0;
        deque<int> q; //store indices
        vector<int> ans;

        while (j < n) {
            while (q.size() && nums[q.back()] < nums[j]) {
                q.pop_back();
            }
            q.push_back(j);

            if (j - i + 1 == k) {
                ans.push_back(nums[q.front()]);
                //move the window
                if (i == q.front()) {
                    q.pop_front();
                }
                i++;
            } else if ( j - i + 1 > k ) {
                //move the window
                if (i == q.front()) {
                    q.pop_front();
                }
                i++;
            }   

            j++;

        }

        return ans;
        
    }
};