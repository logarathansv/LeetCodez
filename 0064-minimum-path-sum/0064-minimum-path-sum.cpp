class Solution {
public: 
    int findmin(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp, int n, int m){
        if(i == 0 && j == 0) 
            return grid[i][j];
        if(i < 0 || j < 0)
            return INT_MAX;
        if(dp[i][j] != -1) return dp[i][j];

        int left = findmin(i-1, j, grid, dp, n, m) ;
        
        int top = findmin(i, j-1, grid, dp, n, m);

        dp[i][j] = min(left, top) + grid[i][j];

        return dp[i][j];

    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        return findmin(n-1, m-1, grid, dp, n, m);
    }
};