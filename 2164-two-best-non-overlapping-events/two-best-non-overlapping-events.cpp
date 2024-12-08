class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        //to make intervals inclusive
        // for (int i = 0; i < events.size() ; i++){
        //     events[i][1]++;
        // }

        vector<vector<int>> intervals;

        for (auto e: events){
            intervals.push_back({e[0],0,e[2]});
            intervals.push_back({e[1],1,e[2]});
        }

        sort(intervals.begin(),intervals.end());

        // for (auto i : intervals){
        //     cout<<i[0]<<" "<<i[1]<<" "<<i[2]<<endl;
        // }

        int prevMax = 0;
        int possibleAns = 0;

        for (auto i: intervals){
            int time = i[0];
            int startingEnding = i[1];
            int value = i[2];

            if (startingEnding == 1){
                prevMax = max(value,prevMax);
            } else {
                possibleAns = max(possibleAns,prevMax + value);
            }

            // cout<<prevMax<<" "<<possibleAns<<endl;

        }

        return possibleAns;
    }

    // Theory
    // https://www.youtube.com/watch?v=gdBsvEOeYho
};