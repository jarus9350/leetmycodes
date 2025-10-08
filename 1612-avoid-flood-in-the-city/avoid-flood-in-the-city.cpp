class Solution {
public:
    int binarySearch(set<int>& zeroes, int lake){
        for (auto ele: zeroes) {
            if (ele > lake) {
                int index = ele;
                zeroes.erase(ele);
                return ele;
            }
        }

        return -1;
    }
    vector<int> avoidFlood(vector<int>& rains) {
        unordered_map<int,int> lakeRained;
        vector<int> ans(rains.size(),1);
        set<int> zeroes;

        for (int i = 0 ; i < rains.size() ; i++){
            int lake = rains[i];
            if (lake == 0) {
                zeroes.insert(i);
            } else {
                if (lakeRained.find(lake) == lakeRained.end()) {
                    lakeRained[lake] = i;
                    ans[i] = -1;
                } else {
                    int lastSeen = lakeRained[lake];
                    lakeRained[lake] = i;
                    int index = binarySearch(zeroes, lastSeen);
                    if (index == -1) return {};
                    ans[index] = lake;
                    ans[i] = -1;
                }
            }
        }

        return ans;
        
    }
};