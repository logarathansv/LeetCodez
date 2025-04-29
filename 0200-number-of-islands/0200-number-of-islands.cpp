class Solution {
public:
    int rows[4] = {-1, 0, 1, 0};
    int cols[4] = {0, 1, 0, -1};

    int n;
    int m;
    
    void dfs(int row, int col, vector<vector<bool>> &vis){
        vis[row][col] = true;

        for(int i=0;i<4;i++){
            int nr = row + rows[i];
            int nc = col + cols[i];

            if(nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc]){
                dfs(nr, nc, vis);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();

        int ct = 0;

        vector<vector<bool>> vis(n, vector<bool>(m));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == '0') vis[i][j] = true;
                else vis[i][j] = false;
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j]){
                    dfs(i, j, vis);
                    ct++;
                }
            }
        }

        return ct;
    }
};