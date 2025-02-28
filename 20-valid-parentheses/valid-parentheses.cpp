class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (auto c : s){
             if (c == '(' || c == '{' || c == '[') {
                st.push(c);
             } else {
                if (st.empty()) return false;
                if (st.size() && st.top() == '(' && c != ')') return false; 
                if (st.size() && st.top() == '{' && c != '}') return false;
                if (st.size() && st.top() == '[' && c != ']') return false;
                st.pop();
             }
        }

        return  (st.size() == 0);


    }
};