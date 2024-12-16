struct Compare {
    bool operator() (const pair<int,int>& a,const pair<int,int>& b){
        if (a.first == b.first){
            return a.second > b.second;
        }
        return a.first > b.first;
    }
};
class Solution {
public:
    bool compare(pair<int,int> a, pair<int,int> b){
        if (a.first == b.first){
            return a.second > b.second;
        }
        return a.first > b.first;
    }
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int len = nums.size();
        vector<int> finalState(len);
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, Compare> pq;

        for (int i = 0 ; i < len ; i++){
            pq.push({nums[i],i});
        }

        while (k--){
            auto [num, index] = pq.top();
            pq.pop();
            pq.push({num*multiplier, index});
        }

        while (pq.size()){
            auto [num, index] = pq.top();
            pq.pop();
            finalState[index] = num;
        }

        return finalState;
        
    }
};