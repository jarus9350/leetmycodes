class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        unordered_set<int> s;
        for (auto n: arr) s.insert(n);

        int ans = 0;

        for (int i = 0 ; i < n - 1 ; i++){
            for (int j = i + 1 ; j < n ; j++){
                int next = arr[i] + arr[j];
                int prev = arr[j];
                int length = 2;


                while (s.find(next) != s.end()){
                    length++;
                    int temp = next;
                    next = prev + next; 
                    prev = temp;

                    ans = max(ans,length);
                }
            }
        }

        return ans;
        
    }
};