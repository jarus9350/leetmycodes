class Solution {
public:
    string numToString(int decimal_number,int len){
        string binary = "";

        while (decimal_number > 0) {
            binary = (decimal_number % 2 == 0 ? "0" : "1") + binary;
            decimal_number /= 2;
        }

        while (binary.length() < len){
            binary = "0" + binary;
        }
        return binary;
    }

    int number(string s){
        int num = 0;
        for (auto c: s){
            num = num*2 + (c - '0');
        }
        return num;
    }

    
    string findDifferentBinaryString(vector<string>& nums) {
        int len = nums[0].size();
        sort(nums.begin(),nums.end());

        int n = 0;
        for (auto s: nums){
            int num = number(s);
            if (num != n){
                break;
            } else {
                n++;
            }
        }


        return numToString(n,len);

        // return s;
        
    }
};