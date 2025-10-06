class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ct = numBottles;

        while(numBottles >= numExchange){
            int q = numBottles/numExchange;
            int r = numBottles%numExchange;

            ct += q;
            numBottles = q+r;
        }

        return ct;
    }
};