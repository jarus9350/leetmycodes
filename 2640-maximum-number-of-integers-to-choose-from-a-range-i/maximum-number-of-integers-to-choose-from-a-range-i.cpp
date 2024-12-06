class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        set<int> s;
        for (auto b: banned){
            if ( 1 <= b && b <= n) s.insert(b);
        }

        long long sum = 0;
        int numbers = 0;
        for (int i = 1 ; i <= n ; i++){
            if ( s.find(i) == s.end()){
                if ( sum + i <= maxSum){
                    sum += i;
                    numbers++;
                } else {
                    break;
                }
            }
        }

        return numbers;
        
    }
};