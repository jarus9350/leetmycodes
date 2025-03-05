class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        int n = heights.size();
        vector<int> ans;
        stack<int> st;

        int i = n - 1;
        for ( ; i >=0 ; i--){
            int h = heights[i];
            while (st.size() && heights[st.top()] < h) {
                st.pop();
            }

            if (st.size() == 0) {
                ans.push_back(i);
            }

            st.push(i);
        }

        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};