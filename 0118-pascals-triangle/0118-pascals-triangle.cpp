class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        int n = numRows;
        vector<vector<int>> dp(numRows+1, vector<int>(numRows+1, 1));

        dp[0][0] = 1;
        dp[1][0] = 1;
        dp[1][1] = 1;

        for(int i=2;i<n;i++){
            for(int j=1;j<i;j++){
                dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
            }
        }

        vector<vector<int>> ans;

        for(int i=0;i<n;i++){
            vector<int> lev;
            for(int j=0;j<i+1;j++){
                lev.push_back(dp[i][j]);
            }

            ans.push_back(lev);
        }

        return ans;
    }
};