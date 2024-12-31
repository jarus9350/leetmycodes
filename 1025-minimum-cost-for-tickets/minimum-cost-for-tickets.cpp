class Solution {
public:
    vector<int> memo;
    int durations[3] = {1, 7, 30};
    int dfs(int index, vector<int>& days, vector<int>& costs){
        if (index == days.size()) return 0;

        if (memo[index] != 0) return memo[index];

        int inter = INT_MAX;

        for (int k = 0 ; k < 3 ; k++){
            int d = durations[k];
            int c = costs[k];

            int j = index;
            int destDay = days[index] + d;
            while ( j < days.size() && days[j] < destDay) {
                j++;
            }

            inter = min(inter, c + dfs(j,days,costs));
        }

        return  memo[index] = inter;
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        memo.resize(366,0);
        int a = dfs(0,days,costs);
        return a;
    }
};

// https://www.youtube.com/watch?v=4pY1bsBpIY4