class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int size = nums.size(); 
        vector<pair<int,int>> nNums;

        for (int i = 0 ; i < size; i++){
            nNums.push_back({nums[i],i});
        }

        sort(nNums.begin(),nNums.end());

        int l = 0;
        int h = size - 1;

        while (l < h){
            if (nNums[l].first + nNums[h].first > target){
                h--;
            } else if (nNums[l].first + nNums[h].first < target){
                l++;
            } else if (nNums[l].first + nNums[h].first == target){
                return {nNums[l].second, nNums[h].second};
            }
        }

        return {};
    }

};