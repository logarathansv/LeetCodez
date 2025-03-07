class Solution {
public:
    bool isPrime(int num){
        if(num == 1) return false;
        if(num < 4) return true;
        for(int i=2;i<=sqrt(num);i++){
            if(num % i == 0) return false;
        }
        return true;
    }
    vector<int> closestPrimes(int left, int right) {
        vector<int> primes;
        int num1 = -1, num2 = -1;
        for(int i=left;i<=right;i++){
            if(isPrime(i)) {
                primes.push_back(i);
            }
        }
        int min = INT_MAX;
        for(int i=1;i<primes.size();i++){
            if(primes[i] - primes[i-1] < min){
                num1 = primes[i-1];
                num2 = primes[i];
                min = primes[i] - primes[i-1];
            } 
        }
        return {num1, num2};
    }
};