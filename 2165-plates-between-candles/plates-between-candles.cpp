class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int len = s.length();
        vector<int> prefixSum; 

        int sum = 0;
        for (int i = 0 ; i < len ; i++){
            sum += ( s[i] == '*' ? 1 : 0);
            prefixSum.push_back(sum);
        }

        int k = 0;
        for (auto s: prefixSum){

            cout<<s<<" ";
        }
        cout<<endl;


        vector<int> left(len,0);
        vector<int> right(len,0);

        for (int i = 0; i < len ; i++){
            if (s[i] == '|'){
                left[i] = i;
            } else {
                left[i] = (i == 0) ?  -1 : left[i-1];
            }
        }

        // for (auto l:  left){
        //     cout<<l<<" ";
        // }
        // cout<<endl;

        for (int i = len - 1; i >= 0 ; i--){
            if (s[i] == '|'){
                right[i] = i;
            } else {
                right[i] = (i == len - 1) ?  -1 : right[i+1];
            }
        }

        //  for (auto l:  right){
        //     cout<<l<<" ";
        // }
        // cout<<endl;



        vector<int> ans;

        for (auto q: queries){
            int l = q[0];
            int r = q[1];

            int rIndex = right[l];
            int lIndex = left[r];

            if (rIndex == -1 || lIndex == -1 ){
                ans.push_back(0);
            } else {
                if (rIndex > lIndex) {
                    ans.push_back(0);
                } else {
                    ans.push_back(  -prefixSum[rIndex] + prefixSum[lIndex]);
                }
                
                
            }
        }

        return ans;
    }
};