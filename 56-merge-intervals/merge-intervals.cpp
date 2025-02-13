class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;

        sort(intervals.begin(),intervals.end());

        int s = intervals[0][0];
        int e = intervals[0][1];

        ans.push_back(intervals[0]);
        for (int i = 1 ; i < intervals.size() ; i++){
            int cs = intervals[i][0];
            int ce = intervals[i][1];
            if ( cs <= e) {
                ans.pop_back();
                ans.push_back({min(s,cs) , max(e,ce)});
                e = max(e,ce);
                s = min(s,cs);
            } else {
                ans.push_back({cs,ce});
                e = ce;
                s = cs;
            }
        }


        return ans;
    }


    // ------
    //     -------
    // -----------

    // -----
    // --------


};