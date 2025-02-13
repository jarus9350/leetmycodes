class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long,vector<long>, greater<long>> pq;
        for (auto n: nums) pq.push(n);

        int count = 0;
        while (pq.size() >= 2) {
            long first = pq.top();
            pq.pop();

            long second = pq.top();
            pq.pop();

            if (first >= k && second >= k) continue;

            long n = min(first,second)*2 + max(first,second);

            pq.push(n);

            count++;
        }

        return count;
        
    }
};