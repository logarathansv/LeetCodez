class Solution {
public:
    int ans = 0;
    int stepup(int n, int ct, vector<int> &memo){
        if(ct > n) return 0;
        if(ct == n) { return 1;}

        if(memo[ct] != -1) return memo[ct];

        memo[ct] = stepup(n, ct+1, memo) + stepup(n, ct+2, memo);
        return memo[ct];
    }
    int climbStairs(int n) {
        vector<int> memo(n+1, -1);

        return stepup(n, 0, memo);
    }
};