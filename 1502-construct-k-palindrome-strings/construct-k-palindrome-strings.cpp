class Solution {
public:
    bool canConstruct(string s, int k) {
        if (k > s.length()) return false;
        vector<int> freq(26,0);

        for (auto ch : s) freq[ch-'a']++;

        int oddFreqChars = 0;

        for (auto f: freq){
            if (f % 2) oddFreqChars++;
        }

        if (oddFreqChars > k) return false;
        return true;        
    }
};