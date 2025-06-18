class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();

        vector<vector<int>> dp(n, vector<int>(m, 0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(obstacleGrid[i][j] == 1){
                    continue;
                }

                if(i == 0 && j == 0){
                    dp[i][j] = 1;
                    continue;
                }

                int ans  = 0;
                if(i > 0){
                    ans += dp[i-1][j];
                }
                if(j > 0){
                    ans += dp[i][j-1];
                }

                dp[i][j] = ans;
            }
        }

        return dp[n-1][m-1];
    }
};