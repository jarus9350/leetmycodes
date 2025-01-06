class Solution {
public:
    vector<int> minOperations(string boxes) {
        int l = boxes.size();
        vector<int> ans(l,0);
        
        int prefixO = 0;
        int prefixC = 0;
        for (int i = 0 ; i < l ; i++){
            if (i == 0){
                if (boxes[i] == '1') prefixO = 1;
                continue;
            }
        
            prefixC = prefixC + prefixO;
            prefixO = prefixO + (boxes[i] == '1' ? 1 : 0);
            ans[i] += prefixC;
        }

        int postfixO = 0;
        int postfixC = 0;
        for (int i = l - 1 ; i >= 0 ; i--){
            if (i == l-1 ){
                if (boxes[l-1] == '1') postfixO = 1;
                continue;
            }

            postfixC = postfixC + postfixO;
            postfixO = postfixO + (boxes[i] == '1' ? 1 : 0);
            ans[i] += postfixC;
        }
        
        return ans;
    }
};