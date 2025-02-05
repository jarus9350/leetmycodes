class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {

        char hold = ' ';
        char hold2 = ' ';

        int index1 = -1, index2 = -1;
        int cnt = 0;

        for (int i = 0 ; i < s1.length() ; i++){
            char c1 = s1[i];
            char c2 = s2[i];

            if (c1 != c2) {
                cnt++;
                if (cnt > 2) return false;

                if (cnt == 1) {
                    index1 = i;
                } else if (cnt == 2) {
                    index2 = i;
                }

                // if (cnt == 1){
                //     hold = s2[i];
                //     s2[i] = c1;
                // } else if (cnt == 2) {
                //     if (hold != s1[i]) {
                //         return false;
                //     }

                //     s2[i] = hold;
                // }
            }
        
        }

        if (cnt == 1) return false;

        if (index1 != -1 && index2 != -1) {
            char temp = s2[index1];
            s2[index1] = s2[index2];
            s2[index2] = temp;
        }
        

        if (s1 != s2) return false; 
        cout<<s1 <<" "<<s2<<endl;

        

        return true;
        
    }
};