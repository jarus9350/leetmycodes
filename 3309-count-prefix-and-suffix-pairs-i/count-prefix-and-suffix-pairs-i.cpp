class Solution {
public:
    int isPrefixAndSuffix(string a, string b){
        return (a == b.substr(0,a.length()) && a == b.substr(b.length() - a.length(),a.length()));
    }

    int countPrefixSuffixPairs(vector<string>& words) {
        int l = words.size();

        int count = 0;
        for (int i = 0; i < l ; i++){
            string w1 = words[i];
            for (int j = i+1; j < l ; j++){
                string w2 = words[j];

                if (i == j) continue;

                if (isPrefixAndSuffix(w1, w2)){
                    count++;
                }
            }
        }

        return count;
    }
};