class Solution {
public:
    bool ans = false;
    void backtrack(int n,int i) {
         if (n == 0) {
            ans = true;
            return;
        }

        if (i > 15) return;
        if (n < 0) return;

        //include power of i
        backtrack(n - (int)pow(3,i),i+1);

        //exclude power of i
        backtrack(n, i+1);
    }

    bool checkPowersOfThree(int n) {
        backtrack(n,0);
        return ans;
    }
};