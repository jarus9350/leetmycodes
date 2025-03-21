class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_set<int> s;

        for (auto n: nums){
            if (n != 0) s.insert(n);
        }

        return s.size();
        
    }
};