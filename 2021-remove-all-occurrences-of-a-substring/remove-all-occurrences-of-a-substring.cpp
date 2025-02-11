class Solution {
public:
    string removeOccurrences(string s, string part) {
        string st = "";
        int partLen = part.length();

        for (auto c : s){
            st.push_back(c);
            int l = st.length() - partLen;
            string inter = (l >= 0) ? st.substr(l) : "";
            if (inter == part) {
                int count = partLen;
                while (count--){
                    st.pop_back();
                }
            }
        }

        return st;
        
    }
};