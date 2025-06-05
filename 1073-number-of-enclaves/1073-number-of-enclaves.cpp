class Solution {
public:
    int rows[4] = {-1, 0, 1, 0};
    int cols[4] = {0, 1, 0, -1};

    void dfs(int r, int c, vector<vector<int>> &vis, vector<vector<int>>& board){
        vis[r][c] = true;        

        for(int i=0;i<4;i++){
            int nr = r + rows[i];
            int nc = c + cols[i];
            if(nr >= 0 && nr < board.size() && nc >=0 && nc < board[0].size() && !vis[nr][nc]
                && board[nr][nc] == 1)
                dfs(nr, nc, vis, board);
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ct = 0;

        vector<vector<int>> vis(n, vector<int>(m, false));

        for(int i=0;i<n;i++){
            if(!vis[i][0] && grid[i][0] == 1) {
                dfs(i, 0, vis, grid);
            }
            if(!vis[i][m-1] && grid[i][m-1] == 1) {
                dfs(i, m-1, vis, grid);
            }
        }

        for(int i=0;i<m;i++){
            if(!vis[0][i] && grid[0][i] == 1) {
                dfs(0, i, vis, grid);
            }
            if(!vis[n-1][i] && grid[n-1][i] == 1) {
                dfs(n-1, i, vis, grid);
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j] == 1) ct++;
            }
        } 

        return ct;
    }
};