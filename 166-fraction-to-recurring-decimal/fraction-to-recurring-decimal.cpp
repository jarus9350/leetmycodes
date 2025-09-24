class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        long long num = numerator;
        long long denom = denominator;
        bool negative = false;
        if ( num < 0 && denom < 0) {
            num*= -1;
            denom*= -1;
        } else if (num< 0 && denom > 0) {
            negative = true;
            num*= -1;
        } else if (num> 0 && denom < 0) {
            negative = true;
            denom*= -1;
        } 
        string result = "";

        if (negative) result.push_back('-');

        long long remainder = 0;
        long long dividend = num;
        long long divisor = denom;
        long long quotient = dividend / divisor;

        unordered_map<int,int> remainIndex;
        bool firstTime = true;

        while (true) {
            remainder = dividend % divisor;
            quotient = dividend/ divisor;
            result += to_string(quotient);

            if (!remainder) return result;

             if (firstTime) {
                if (remainder) {
                    result.push_back('.');
                } else {
                    return result;
                }
                firstTime = false;
            }

            if (remainIndex.find(remainder) == remainIndex.end()) {
                remainIndex[remainder] = result.size();
            } else {
                result.insert(remainIndex[remainder],1,'(');
                result.push_back(')');
                return result;
            }
            
            dividend = remainder*10;

        }
    }
};