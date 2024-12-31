class Solution {
public:
    vector<int> memo;
    int dfs(int index, vector<int>& days, vector<int>& costs){
        if (index == days.size()) return 0;

        if (memo[index] != 0) return memo[index];

        // 1 day
        int j = index;
        int destDay = days[index] + 1;
        while ( j < days.size() && destDay > days[j] ) {
            j++;
        }

        int a = costs[0] + dfs(j,days,costs);

        // 1 week
        j = index;
        destDay = days[index] + 7;
        while ( j < days.size() && destDay > days[j] ) {
            j++;
        }

        int b = costs[1] + dfs(j,days,costs);

        // 1 month
        j = index;
        destDay = days[index] + 30;
        while ( j < days.size() && destDay > days[j] ) {
            j++;
        }

        int c = costs[2] + dfs(j,days,costs);

        return  memo[index] = min(a,min(b,c));
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        memo.resize(366,0);
        int a = dfs(0,days,costs);
        return a;
    }
};

// https://www.youtube.com/watch?v=4pY1bsBpIY4