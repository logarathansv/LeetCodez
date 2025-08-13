class Solution {
public:
    bool isPowerOfThree(int n) {
        for(long i=0;i*i*i<=n;i++){
            if(n == (pow(3, i))) return true;
        }

        return false;
    }
};