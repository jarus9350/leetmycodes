class Solution {
public:
    bool isVowel(char& c){
        if (tolower(c) == 'a' || tolower(c) == 'e' || tolower(c) == 'i' || tolower(c) == 'o' || tolower(c) == 'u') return true;
        return false;
    }

    string sortVowels(string s) {
        vector<char> vowels;
        for (auto c: s){
            if (tolower(c) == 'a' || tolower(c) == 'e' || tolower(c) == 'i' || tolower(c) == 'o' || tolower(c) == 'u') vowels.push_back(c);
        }

        sort(vowels.begin(),vowels.end());

        string ans = "";
        int index  = 0;
        for (auto c: s) {
            if (!isVowel(c)) {
                ans.push_back(c);
            } else {
                ans.push_back(vowels[index++]);
            }
        }

        return ans;

        // for (auto c: vowels){
        //     cout<< c<<endl;
        // }

        // return "";        
    }
};