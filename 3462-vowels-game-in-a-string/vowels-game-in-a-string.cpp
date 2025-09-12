class Solution {
public:
    bool isVowel(char& c) {
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }
    bool doesAliceWin(string s) {
        int count = 0;
        for (auto& c: s) {
            if (isVowel(c)) return true;
        }

        return false;
    }
};