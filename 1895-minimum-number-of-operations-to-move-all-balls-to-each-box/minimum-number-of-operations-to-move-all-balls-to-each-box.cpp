class Solution {
public:
    vector<int> minOperations(string boxes) {
        int l = boxes.size();
        vector<int> ans(l,0);

        vector<int> prefixCost(l,0);
        vector<int> prefixOnes(l,0);

        vector<int> postfixCost(l,0);
        vector<int> postfixOnes(l,0);

        // for (int i = 1 ; i < l ; i++){
        //     prefixCost[i] = ((boxes[i-1] == '1') ? 1 : 0) + prefixCost[i-1];
        // }

        // for (int i = l - 2; i >= 0  ; i--){
        //     postfixCost[i] = ((boxes[i+1] == '1') ? 1 : 0) + postfixCost[i+1];
        // }
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



        // for (auto p : prefixCost){
        //     cout<<p<<" ";
        // }
        // cout<<endl;

        // for (auto p : postfixCost){
        //     cout<<p<<" ";
        // }
        // cout<<endl;

        // for (int i = 0 ; i < l ; i++){
        //     ans[i] = prefixCost[i] + postfixCost[i];
        // }

        // for (int i = 0 ; i < l ; i++){
        //     int count = 0;
        //     for (int j = 0 ; j < l ; j++){
        //         if (i != j){
        //             if (boxes[j] == '1'){
        //                 count += abs(j-i);
        //             }
        //         }
        //     }
        //     ans[i] = count;
        // }


        
        return ans;
    }
};