class Solution {
public:
    static const int MOD = 1e9 + 7;

    int way(int ct, int sum, int n, int x, vector<vector<int>> &memo, vector<int> &powers){
        if(sum == n) return 1;
        else if(sum > n || ct >= powers.size()) return 0;

        if(memo[ct][sum] != -1) return memo[ct][sum];

        int t = way(ct+1, sum + powers[ct], n, x, memo, powers);
        int nt = way(ct+1, sum, n, x, memo, powers); 

        return memo[ct][sum] = (t+nt) % MOD;
    }
    int numberOfWays(int n, int x) {
        vector<int> powers;

        for (int base = 1; ; ++base) {
            long long p = pow(base, x);
            if (p > n) break;
            powers.push_back((int)p);
        }

        vector<vector<int>> memo(powers.size(), vector<int>(n+1, -1));

        return way(0, 0, n, x, memo, powers);
    }
};