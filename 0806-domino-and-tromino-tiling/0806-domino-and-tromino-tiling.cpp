class Solution {
public:
    int memo[1000] = {};
    long long MOD = 1000000007;
    int numTile(int n){
        if(n == 1) return 1;
        else if(n == 2) return 2;
        else if(n == 3) return 5;
        else if(n < 1) return 0;

        cout<<n<<" ";
        if(memo[n] != 0) return memo[n]%MOD;
        
        
        memo[n] = ((numTile(n-1) * 2)%MOD + numTile(n-3)%MOD)%MOD; 
        return memo[n];
    }
    int numTilings(int n) {
        return numTile(n);
    }
};