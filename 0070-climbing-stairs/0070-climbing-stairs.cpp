class Solution {
public:
    int find(int ind, int size, vector<int>& dp){
        if(ind == 0 || ind == 1) return 1;
        if(dp[ind] != -1) return dp[ind];

        return dp[ind] = find(ind-1, size, dp) + find(ind-2, size, dp); 
    }
    int climbStairs(int n) {
        vector<int> dp(n+1, -1);

        dp[0] = 1;
        dp[1] = 1;

        for(int i=2;i<=n;i++){
            dp[i] = dp[i-1] + dp[i-2];
        }

        return dp[n];
        // return find(n, n, dp);
    }
};