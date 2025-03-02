class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        unordered_map<int,int> mp;
        for (auto n: nums1) {
            int id = n[0];
            int num = n[1];
            mp[id] += num;
        }

        for (auto n: nums2) {
            int id = n[0];
            int num = n[1];
            mp[id] += num;
        }

        vector<vector<int>> ans;
        for (auto [key,value] : mp) ans.push_back({key,value});
        sort(ans.begin(),ans.end());
        return ans;
        
    }
};