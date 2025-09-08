class Solution {
public:
    bool noZero(string& n){
        for (int i = 0 ; i < n.size(); i++){
            if (n[i] == '0'){
                return false;
            }
        }

        return true;
    }

    vector<int> getNoZeroIntegers(int n) {
        for (int i = 1; i < n ; i++){
            int secondNum = n - i;
            string s = to_string(i);
            string s2 = to_string(secondNum);
            if (noZero(s) && noZero(s2)){   
                return {i, n - i};
            }
        }

        return {0,0};
        
    }
};