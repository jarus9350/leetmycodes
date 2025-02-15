class Solution {
public:
    bool isPunishmentNumber(int n, string s){
        if (s.length() == 0 && n == 0) return true;
        if (s.length() == 0 ) return false;

        bool ans = false;
        for (int i = 1 ; i <= s.length() ; i++){
            string start = s.substr(0,i);
            int number = stoi(start);
            ans = ans || isPunishmentNumber(n - number, s.substr(i));
        }

        return ans;
    }

    int punishmentNumber(int n) {
        int ans = 0;
        for (int i = 1 ; i <= n ; i++){
            int num = i*i;
            string s = to_string(num);
            if (isPunishmentNumber(i, s)) {
                ans += num;
            }
        }

        return ans;
    }
};