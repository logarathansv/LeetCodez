class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<pair<int, int>, int>> q;

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> visited(n, vector<int> (m));
        int ans = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                    visited[i][j] = 2;
                }
                else if(grid[i][j] == 0) visited[i][j] = 0;
                else visited[i][j] = 1;
            }
        }

        int rows[] = {-1, 0, 1, 0};
        int cols[] = {0, 1, 0, -1};

        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop();

            ans = max(ans, t);

            for(int i=0;i<4;i++){
                int nr = r + rows[i];
                int nc = c + cols[i];
                if(nr > -1 && nr < n && nc > -1 && nc < m && visited[nr][nc] == 1){
                    visited[nr][nc] = 2;
                    q.push({{nr, nc}, t+1});
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visited[i][j] == 1) return -1;
            }
        }

        return ans;
    }
};