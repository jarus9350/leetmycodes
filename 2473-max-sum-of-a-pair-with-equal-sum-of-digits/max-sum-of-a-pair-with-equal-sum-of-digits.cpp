class Solution {
public:

    int digitSum(int num){
        int sum = 0;
        while (num) {
            int n = num % 10;
            num = num / 10;
            sum += n;
        }
        return sum;
    }

    int maximumSum(vector<int>& nums) {
        unordered_map<int,multiset<int>> mp;

        int ans = 0;

        for (int i = 0 ; i < nums.size(); i++){
            int number = nums[i];
            int n = digitSum(number);
            mp[n].insert(number);
        }

        for (auto [key, s] : mp ){
            if (s.size() >= 2) {
                auto it = s.rbegin(); 
                int first = *it;
                ++it;
                int second = *it;

                ans = max(ans, first + second);
            }
        }

        return ans == 0 ? -1 : ans;
        
    }
};


