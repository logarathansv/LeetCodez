class Solution {
public:
    // int stepup(int n, int ct, vector<int> &memo){
    //     if(ct > n) return 0;
    //     if(ct == n) { return 1;}

    //     if(memo[ct] != -1) return memo[ct];

    //     memo[ct] = stepup(n, ct+1, memo) + stepup(n, ct+2, memo);
    //     return memo[ct];
    // }
    int climbStairs(int n) {
        vector<int> dp(n+1, -1);

        dp[0] = 1;
        dp[1] = 2;

        for(int i=2;i<n;i++){
            dp[i] = dp[i-1] + dp[i-2];
        }

        // return stepup(n, 0, memo);
        return dp[n-1];
    }
};