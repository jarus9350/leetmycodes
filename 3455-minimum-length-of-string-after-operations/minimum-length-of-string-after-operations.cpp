class Solution {
public:
    int minimumLength(string s) {
        vector<int> freq(26,0);

        for (auto c: s){
            freq[c - 'a']++;
        }

        int count = 0;

        for (int i = 0 ; i < 26 ; i++){
            auto f = freq[i];
            // cout<<i<<" "<<f<<endl;

            if (f >= 3 ){
                if (f % 2){
                    // cout<<i<<" "<<f<<endl;
                    count++;
                } else {
                    // cout<<i<<" "<<f<<endl;
                    count += 2;
                }
            } else {
                // cout<<i<<" "<<f<<endl;
                count += f;
            }

            char ch = 'a' + i;
            cout<<ch<<" "<<f<<" "<<count<<endl;
        }

        return count;
    }
};