class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<int> prefixSum(n,0);
        set<char> s = {'a', 'e', 'i', 'o', 'u'};

        int count = 0;
        for (int i = 0 ; i < n ; i++){
            auto w = words[i];
            if (s.find(w.front()) != s.end() && s.find(w.back()) != s.end()){
                cout<<w<<" "<<i<<endl;
                count++;
            }
            prefixSum[i] = count;
        }

        // for (auto a: prefixSum){
        //     cout<<a<<" ";
        // }
        // cout<<endl;

        vector<int> ans;

        for (auto q: queries){
            int s = q[0];
            int e = q[1];

            int qAns = prefixSum[e] -  ((s == 0) ? 0 : prefixSum[s-1]);
            ans.push_back(qAns);
        }

        return ans;
        
    }
};