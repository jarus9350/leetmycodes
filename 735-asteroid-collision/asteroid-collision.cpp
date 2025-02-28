class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st;
        for (int asteroid : asteroids){
            while (st.size() && asteroid < 0 && st.back() > 0) {
                int diff = st.back() + asteroid;
                if (diff > 0) {
                    asteroid = 0;
                } else if (diff == 0) {
                    asteroid = 0;
                    st.pop_back();
                } else if (diff < 0){
                    st.pop_back();
                }
            }

            if (asteroid) {
                st.push_back(asteroid);
            }
            
        }

        return st;
    }
};