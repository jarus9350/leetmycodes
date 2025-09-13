class Solution {
public:
    bool isVowel(char& c) {
        return (c == 'a' || c== 'e' || c == 'i' || c == 'o' || c == 'u');
    }

    int maxFreqSum(string s) {
        vector<int> freq(26,0);
        for (auto c: s){
            freq[c - 'a']++;
        }

        int maxVowel = 0;
        int maxC = 0;
        for (auto c: s){
            if (isVowel(c)){
                maxVowel = max(maxVowel,freq[c-'a']);
            }

            if (!isVowel(c)){
                maxC = max(maxC, freq[c-'a']);
            }
        }

        return maxVowel + maxC;

        
    }
};