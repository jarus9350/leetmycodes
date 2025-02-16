class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int> mp;
        for (auto c: s) mp[c]++;

        priority_queue<pair<int,char>> pq;
        for (auto [key,val] : mp) pq.push({val,key});

        string ans = "";
        char prev = ' ';
        
        while (pq.size()){
            auto [val1, key1] = pq.top(); pq.pop();

            if (prev == key1) {
                if (pq.size()) {
                    auto [val2, key2] = pq.top(); pq.pop();
                    ans.push_back(key2);
                    if (val2 > 1) pq.push({val2-1, key2});
                    prev = key2;
                } else {
                    return "";
                }
            
                pq.push({val1,key1});
            } else {
                ans.push_back(key1);
                if ( val1 > 1) pq.push({val1-1, key1});
                prev = key1;
            }
        }

        cout<<ans<<endl;

        return ans;
    }
};