class Solution {
public:
    int countBits(int num){
        int count = 0;
        unsigned int x = (unsigned int)num;
        while (x) {
            if (x & 1) count++;
            x = x >> 1;
        }

        return count;
    }
    int makeTheIntegerZero(int num1, int num2) {
        for (int i = 1 ; i <= 60 ; i++){
            long long num = (long long)num1 - (long long)i*num2;
            if (num < 0 ) return -1;
            int bits = __popcount(num);
            if (bits <= i && i <= num) return i;
        }

        return -1;
        
    }
};