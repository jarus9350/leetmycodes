class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int count = 0;
        while (numBottles >= numExchange) {
            numBottles -= numExchange;
            count+= numExchange;
            numBottles += 1;
            numExchange += 1;
        }

        return count + numBottles;
        
    }
};