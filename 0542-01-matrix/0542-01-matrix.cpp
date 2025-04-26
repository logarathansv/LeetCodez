class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> vis(mat.size(), vector<int>(mat[0].size()));

        int n = mat.size();
        int m = mat[0].size();

        int rows[] = {-1, 0, 1, 0};
        int cols[] = {0, 1, 0, -1};

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j] == 0) {
                    vis[i][j] = true;
                    q.push({{i, j}, 0});
                }
                else    vis[i][j] = false;
                 
            }
        }

        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int val = q.front().second;
            mat[r][c] = val;

            q.pop();

            for(int i=0;i<4;i++){
                int nr = r + rows[i];
                int nc = c + cols[i];

                if(nr >= 0 && nr < n && nc >= 0 && nc < m){
                    if(!vis[nr][nc]){
                        vis[nr][nc] = true;

                        q.push({{nr, nc}, val+1});
                    }
                }
            }
        }
        return mat;
    }
};