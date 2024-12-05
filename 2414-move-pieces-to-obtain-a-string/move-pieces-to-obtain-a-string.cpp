class Solution {
public:
    bool canChange(string start, string target) {
        int len = start.length();

        int p1 = 0;
        int p2 = 0;

        while ( p1 < len && p2 < len){
            while (start[p1] == '_') p1++;
            while (target[p2] == '_')p2++;


            if (start[p1] == target[p2]){
                if (start[p1] == 'L'){
                    if (p1 < p2) return false;
                }

                if (start[p1] == 'R'){
                    if (p1 > p2) return false;
                }
            } else {
                return false;
            }

            p1++;
            p2++;

        }

        while ( p1 < len && start[p1] == '_'){
            p1++;
        }

        if (p1 < len) return false;

        if (p1 == len){
            while (target[p2] == '_'){
                p2++;
            }
        }

        if (p2 < len) return false;

        return true;
        
    }
};