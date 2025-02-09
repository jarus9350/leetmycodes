class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long n = nums.size();
        unordered_map<int,int> diffFreq;

        long long total = n*(n - 1)/2;
        for (int j = 0 ; j < n ; j++){
            int currDiff = (j - nums[j]);
            if (diffFreq.find(currDiff) != diffFreq.end()){
                int times = diffFreq[currDiff];
                total -= times;
            }
            diffFreq[j - nums[j]]++;
        }

        return total;
    }
};

// j - i != nums[j] - nums[i];

// j - nums[j] != i - nums[i];