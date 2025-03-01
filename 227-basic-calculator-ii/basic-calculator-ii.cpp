class Solution {
public:
    int calculate(string s) {
        s += "+";

        char operation = '+';

        int prevNum = 0;
        int ans = 0;
        int num = 0;

        for (auto c: s){
            if (c == ' ') continue;
            if ( '0' <= c && c <= '9') {
                num = num*10 + (c - '0');
            } else {
                if ( operation == '*' ) {
                    ans = ans - prevNum + (prevNum*num);
                    prevNum = (prevNum*num);
                } else if ( operation == '/') {
                    ans = ans - prevNum + (prevNum/num);
                    prevNum = (prevNum/num);
                } else if ( operation == '+') {
                    ans += num;
                    prevNum = num;
                } else if ( operation == '-') {
                    ans += -num;
                    prevNum = -num;
                }

                num = 0;
                operation = c;
            }
        }

        return ans;
        
    }
};