class Solution {
public:
    // int findminpath(int i, int j, int n, int m, vector<vector<int>>& mat, vector<vector<int>>& memo) {
    //     if (j < 0 || j >= m) return INT_MAX;
    //     if (i == n-1) return mat[i][j];
        
    //     if (memo[i][j] != -1) return memo[i][j];
        
    //     int downLeft = findminpath(i+1, j-1, n, m, mat, memo);
    //     int down = findminpath(i+1, j, n, m, mat, memo);
    //     int downRight = findminpath(i+1, j+1, n, m, mat, memo);
        
    //     memo[i][j] = mat[i][j] + min({downLeft, down, downRight});
    //     return memo[i][j];
    // }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> memo(n, vector<int>(m, 0));

        for(int i=0;i<m;i++){
            memo[0][i] = matrix[0][i];
        }
        
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                int bl = matrix[i][j], bb = matrix[i][j], br = matrix[i][j];

                if(j < m-1) bl += memo[i-1][j+1];
                else bl += INT_MAX/100;
                if(j > 0) br += memo[i-1][j-1];
                else br += INT_MAX/100;

                bb += memo[i-1][j];

                memo[i][j] = min(min(bl, br), bb);
            }
        }

        int result = INT_MAX;
        // for (int j = 0; j < m; j++) {
        //     result = min(result, findminpath(0, j, n, m, matrix, memo));
        // }
        for(int i=0;i<m;i++){
            result = min(result, memo[n-1][i]);
        }

        return result;
    }
};