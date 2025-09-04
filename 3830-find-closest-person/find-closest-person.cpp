class Solution {
public:
    int findClosest(int x, int y, int z) {
        int dist1 = x - z;
        int dist2 = y - z;

        if (dist1 < 0) {
            dist1 *= -1;
        }

        if (dist2 < 0){
            dist2 *= -1;
        }

        if (dist1 < dist2) return 1;
        else if (dist2 < dist1) return 2;
        
        return 0;
    }
};