class Solution {
public:
    vector<int> minOperations(string boxes) {
        int l = boxes.size();
        vector<int> ans(l,0);

        for (int i = 0 ; i < l ; i++){
            int count = 0;
            for (int j = 0 ; j < l ; j++){
                if (i != j){
                    if (boxes[j] == '1'){
                        count += abs(j-i);
                    }
                }
            }
            ans[i] = count;
        }
        
        return ans;
    }
};