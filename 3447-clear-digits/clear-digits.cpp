class Solution {
public:
    string clearDigits(string s) {
        int len = s.length();
        int count = 0;

        string newS = "";
        for (auto c : s){
            if (c >= 'a' && c <= 'z' ){
                newS.push_back(c);
            } else {
                newS.pop_back();
            }
        }



        return newS;
        
    }
};