class Solution {
public:
    int rows[4] = {-1, 0, 1, 0};
    int cols[4] = {0, 1, 0, -1};

    void dfs(int r, int c, vector<vector<int>> &vis, vector<vector<char>>& board){
        vis[r][c] = true;        

        for(int i=0;i<4;i++){
            int nr = r + rows[i];
            int nc = c + cols[i];
            if(nr >= 0 && nr < board.size() && nc >=0 && nc < board[0].size() && !vis[nr][nc]
                && board[nr][nc] == 'O')
                dfs(nr, nc, vis, board);
        }
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<int>> vis(n, vector<int>(m, false));

        for(int i=0;i<n;i++){
            if(!vis[i][0] && board[i][0] == 'O') {
                dfs(i, 0, vis, board);
            }
            if(!vis[i][m-1] && board[i][m-1] == 'O') {
                dfs(i, m-1, vis, board);
            }
        }

        for(int i=0;i<m;i++){
            if(!vis[0][i] && board[0][i] == 'O') {
                dfs(0, i, vis, board);
            }
            if(!vis[n-1][i] && board[n-1][i] == 'O') {
                dfs(n-1, i, vis, board);
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && board[i][j] == 'O') board[i][j] = 'X';
            }
        } 
    }
};