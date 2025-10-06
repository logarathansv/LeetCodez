class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int ct = numBottles;

        while(numBottles >= numExchange){
            bool f = 0;
            int q = numBottles-numExchange;
            if(q >= 0) {ct++;f=1;}
            else break;

            numBottles = (f==1) ? q+1:q;
            numExchange++;
        }

        return ct;
    }
};