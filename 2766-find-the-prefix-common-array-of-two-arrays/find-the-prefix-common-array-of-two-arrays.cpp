class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int s = A.size();
        vector<int> ans(s,0);
        set<int> st;

        int elementsAdded = 0;
        for (int i = 0; i < A.size() ; i++ ){
            elementsAdded += 2;
            st.insert(A[i]);
            st.insert(B[i]);

            ans[i] = elementsAdded - st.size();
        }

        return ans;
    }
};