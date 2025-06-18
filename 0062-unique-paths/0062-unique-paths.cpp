class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> memo(m, vector<int>(n, -1));
        return countPath(m-1,n-1,m,n, memo);
    }
    int countPath(int i,int j,int m,int n,vector<vector<int>> &memo){
        if(i==0 && j==0){
            return 1;
        }
        
        if(i < 0 || j < 0) 
            return 0;

        if(memo[i][j] != -1) return memo[i][j]; 
        
        int right = countPath(i, j-1, m, n, memo);
        int down = countPath(i-1, j, m, n, memo);

        memo[i][j] = right + down;

        return memo[i][j];
    }
};