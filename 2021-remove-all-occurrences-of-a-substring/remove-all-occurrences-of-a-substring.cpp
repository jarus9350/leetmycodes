class Solution {
public:
    string removeOccurrences(string s, string part) {
        string st = "";
        int partLen = part.length();

        for (auto c: s){
            st.push_back(c);
            int currLen = st.size();
            int index = currLen - partLen;
            
            string inter = (index >= 0) ? st.substr(index) : "";

            if (inter == part) {
                int temp = partLen;
                while(temp--) st.pop_back();
            }
        }

        return st;
        
    }

    // 01234
    // suraj
};