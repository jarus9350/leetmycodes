class Solution {
public:
    long long flowerGame(int n, int m) {
        // if ( (n+m) % 2 == 0) return 0;

        // if (n > m) swap(n,m);

        long long ans = (long long)n * (long long)(m)/2;

        // for (int i = 1 ; i <= m ; i++){
        //     int l = 1;
        //     int h = n;
        //     while ( l < h) {
        //         int mid  = l + (h - 1)/2;


        //     }
        // }


        return ans;
        
    }
};