class Solution {
public:
    bool bruteforce(int i,vector<int>& ans,int n, int l,set<int>& used) {
        if (i == n) return true;

        for (int num = l ; num >= 1 ; num-- ){
            if (used.find(num) != used.end()) continue;
            if (num > 1 && ( i + num >= n  || ans[i+num])) continue;


            // taking decision
            used.insert(num);
            ans[i] = num;
            if (num > 1) {
                ans[i+num] = num;
            }

            int j = i + 1;
            while (j < n && ans[j] != 0) j++;


            bool rec = bruteforce(j, ans, n, l, used);
            if (rec) {
                return true;
            } 

            // undo decision
            used.erase(num);
            ans[i] = 0;
            if (num > 1) {
                ans[i+num] = 0;
            }
        }

        return false;
    }

    vector<int> constructDistancedSequence(int n) {
        set<int> used;
        vector<int> ans(2*n - 1,0);

        bruteforce(0,ans,2*n -1,n,used);
        return ans;
    }
};