class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int countSetBits = 0;
        for (int i = 0 ; i < 32 ; i++){
            if (num2 & 1) countSetBits++;
            num2 = num2 >> 1;
        }
        // cout<<countSetBits<<endl;

        vector<int> num(32,0);
        int number = 0;

        for (int i = 31 ; i >= 0 && countSetBits; i--){
            if ( num1 & (1 << i)) {
                num[i] = 1;
                countSetBits--;
            }
        }

        // cout<<countSetBits<<endl;

        for (int i = 0 ; i < 32 && countSetBits; i++){
            if (num[i] == 0){
                num[i] = 1;
                countSetBits--;
            }
        }

        // cout<<countSetBits<<endl;

        int ans = 0;
        for (int i = 31; i >= 0 ; i--){
            ans = ans*2 + num[i];
        }



        // cout<<countSetBits<<endl;

        return ans;
    }
};