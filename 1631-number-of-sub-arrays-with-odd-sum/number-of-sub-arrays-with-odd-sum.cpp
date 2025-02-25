class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        int n = arr.size();
        
        int sum = 0;
        int oddCount = 0;
        int evenCount = 1;

        int ans = 0;   

        for (int i = 0 ; i < n; i++){
            sum += arr[i];

            if (sum % 2 == 0){
                ans = (ans + oddCount) % MOD;
                evenCount++;
            }

            if (sum % 2) {
                ans = (ans +  evenCount) % MOD;
                oddCount++;
            }

        }

        return ans;
        
    }
};