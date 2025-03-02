class Solution {
public:
    vector<string> az = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string> dfs(string digits,int i, int n) {
        if (i == n) return {""};

        int num = digits[i] - '0';
        vector<string> s = dfs(digits,i+1,n);
        vector<string> ans;
        for (auto str: s) {
            for (auto c: az[num-2]) {
                ans.push_back(c + str);
            }
        }

        return ans;
    }

    vector<string> letterCombinations(string digits) {
        int n = digits.size();
        if (n == 0) return {};
        return dfs(digits,0,n);
    }
};