class Solution {
public:
    static const int MAXN = 50000;
    int t[4*MAXN];

    void build(vector<int>& a, int v, int tl, int tr) {
        if (tl == tr) {
            t[v] = tl;
        } else {
            int tm = (tl + tr) / 2;
            build(a, v*2, tl, tm);
            build(a, v*2+1, tm+1, tr);

            if ( a[t[v*2]] > a[t[v*2 + 1]]){
                t[v] = t[v*2];
            } else {
                t[v] = t[v*2 + 1];
            }
        }
    }

    int maximum(vector<int>& a,int v, int tl, int tr, int l, int r) {
        if(tl >= l and tr <= r) return t[v];
        if(tl > r or tr < l) return INT_MIN;

        int tm = tl + (tr - tl) /2;
        int left_max = maximum (a,2*v, tl, tm,l,r);
        int right_max = maximum(a,2*v+1, tm+1, tr,l, r);
        if(left_max == INT_MIN) return right_max;
        if(right_max == INT_MIN) return left_max;
        return a[left_max] >= a[right_max] ? left_max: right_max;
    }   


    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n = heights.size();
        build(heights,1,0,n-1);

        vector<int> ans;

        for (auto q: queries){
            int alice = q[0];
            int bob = q[1];

            if (bob < alice){
                swap(alice,bob);
            }

            //hint 2
            if ( alice == bob || heights[bob] > heights[alice]) {
                ans.push_back(bob);
                continue;
            }
            
            // cout<<"yahan pe aa gae oee"<<endl;
            //binary search
            int l = bob+1;
            int h = n - 1;
            //int maxBetweenAB = max(heights[alice],heights[bob]);

            int inter = INT_MAX;
            while (l <= h){
                int mid = l + (h - l)/2;
                int maxInRange = maximum(heights,1, 0, n-1, l, mid);

                if (heights[maxInRange] > heights[alice]){
                    inter = min(inter, maxInRange);
                    h = mid - 1;
                } else {
                    l = mid + 1;
                }
            }

            if (inter == INT_MAX){
                ans.push_back(-1);
            } else {
                ans.push_back(inter);
            }

        }

        return ans;
        
    }
};