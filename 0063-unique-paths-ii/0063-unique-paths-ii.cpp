class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();

        vector<int> dp(n, 0);

        for(int i=0;i<n;i++){

            vector<int> tp(m, 0);

            for(int j=0;j<m;j++){
                if(obstacleGrid[i][j] == 1){
                    continue;
                }

                if(i == 0 && j == 0){
                    tp[i] = 1;
                    continue;
                }

                if(i > 0){
                    tp[j] += dp[j];
                }
                if(j > 0){
                    tp[j] += tp[j-1];
                }
            }

            dp = tp;
        }

        return dp[m-1];
    }
};