class Solution {
public:
    int minFlips(int a, int b, int c) {
        int ct = 0;

        while(max({a, b, c})){
            if(((a & 1) | (b & 1)) != (c & 1)){
                if((!(a & 1) | (b & 1)) == (c & 1)) ct++;
                else if(((a & 1) | !(b & 1)) == (c & 1)) ct++;
                else ct+=2;
            }

            a >>= 1;
            b >>= 1;
            c >>= 1;
        }

        return ct;
    }
};