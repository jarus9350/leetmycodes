class Solution {
public:
    long long minOperations(vector<vector<int>>& queries) {
        long long ans = 0;
        for (auto q: queries){
            long long s = q[0];
            long long e = q[1];

            long long steps = 1;
            long long L = 1;
            long long R = 4*L - 1;

            long long inter = 0;

            while (true){
                long long l = max(L,s);
                long long r = min(R,e);

                if (l <= r){
                    long long elements = r - l + 1;
                    long long operations = elements*steps;
                    inter += operations;
                }     

                steps++;
                L = 4*L;
                R = 4*L - 1;

                if (L > e) break;
            }

            ans += (inter + 1)/2;


        }

        return ans;
    }
};