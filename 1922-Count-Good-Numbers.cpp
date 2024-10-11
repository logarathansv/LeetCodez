#define mod 1000000007
class Solution {
private:
    long long power(long long x, long long n){
        if(n == 0){
            return 1;
        }
        long long ans = power(x, n/2);
        ans *= ans;
        ans %= mod;
        if(n%2==1){
            ans *= x;
            ans %= mod;
        }
        return ans;
    }
public:
    int countGoodNumbers(long long n) {
        return (power(5, n/2 + n%2) * power(4, n/2))%mod;
    }
};