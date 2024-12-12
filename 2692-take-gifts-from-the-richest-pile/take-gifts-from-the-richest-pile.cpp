class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq;

        for (auto g: gifts){
            pq.push(g);
        }

        while (k--){
            int top = pq.top();
            pq.pop();
            int flooredVal = floor(sqrt((double)top));
            pq.push(flooredVal);
        }

        long long ans = 0;
        while (pq.size()){
            int top = pq.top();
            pq.pop();

            ans += top;
        }

        return ans;
        
    }
};