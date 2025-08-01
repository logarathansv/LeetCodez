class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        int n = numRows;
        vector<vector<int>> dp(numRows+1);

        dp[0].push_back(1);
        dp[1].push_back(1);
        dp[1].push_back(1);

        for(int i=2;i<n;i++){
            dp[i].push_back(1);
            for(int j=1;j<i;j++){
                dp[i].push_back(dp[i-1][j] + dp[i-1][j-1]);
            }
            dp[i].push_back(1);
        }

        // vector<vector<int>> ans;

        // for(int i=0;i<n;i++){
        //     vector<int> lev;
        //     for(int j=0;j<i+1;j++){
        //         lev.push_back(dp[i][j]);
        //     }

        //     ans.push_back(lev);
        // }
        dp.resize(n);

        return dp;
    }
};