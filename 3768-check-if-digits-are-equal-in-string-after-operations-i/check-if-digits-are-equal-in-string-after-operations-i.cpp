class Solution {
public:
    bool hasSameDigits(string s) {
        string ns = "";
        while (s.size() > 2) {
            for (int i = 0 ; i < s.length() - 1 ; i++){
                ns.push_back((char)(((int)(s[i] - '0') + (int)(s[i+1] - '0'))%10));
            }
            s = ns;
            ns = "";
            cout<<s<<endl;
        }

        cout<<s<<endl;
        return s[0] == s[1];
        
    }
};