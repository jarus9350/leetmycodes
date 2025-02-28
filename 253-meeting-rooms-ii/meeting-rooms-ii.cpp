class Solution {
public:
    bool static compare(pair<int,int>& a,pair<int,int>& b) {
        if (a.first < b.first) {
            return true;
        } else if (a.first == b.first){
            return a.second > b.second;
        }

        return false;
    }

    int minMeetingRooms(vector<vector<int>>& intervals) {
        vector<pair<int,int>> v;
        for (auto interval : intervals){
            int st = interval[0];
            int et = interval[1];

            v.push_back({st,0});
            v.push_back({et,1});
        }

        sort(v.begin(),v.end(),compare);

        int maxRooms = 0;
        int rooms = 0;
        for (auto &[time,event] : v){
            if (event == 0) { //start
                rooms++;
                maxRooms = max(maxRooms,rooms);
            } else { //end
                rooms--;
                maxRooms = max(maxRooms, rooms);
            }
        }

        return maxRooms;
        
    }
};