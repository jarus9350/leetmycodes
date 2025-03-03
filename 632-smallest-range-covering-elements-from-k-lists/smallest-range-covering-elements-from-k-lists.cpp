class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<vector<int>> n;

        for (int i = 0 ; i < nums.size() ; i++){
            for (int j = 0 ; j < nums[i].size() ; j++) {
                n.push_back({nums[i][j],i});
            }
        }

        sort(n.begin(),n.end());
        unordered_map<int,int> mp; // num,index

        int i = 0;
        int j = 0;
        int s = n.size();
        int ws = nums.size();
        int count = 0;

        int minRange = INT_MAX;
        vector<int> ans;
        while (j < s) {
            int number = n[j][0];
            int row = n[j][1];

            mp[row]++;
            if (mp[row] == 1) count++;

            while ( ws == count) {
                int startNum = n[i][0];
                int startRow = n[i][1];

                int range = number - startNum;

                if (minRange > range) {
                    minRange = range;
                    ans = {startNum,number};
                }

                mp[startRow]--;
                if (mp[startRow] == 0) {
                    count--;
                }

                i++;
            }

            j++;
        }

        return ans;
        
    }
};