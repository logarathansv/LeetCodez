class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] == 0 && n == 1) return 1; 
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;

        int drow[] = {1, 0, -1, -1, -1, 0, 1, 1};
        int dcol[] = {-1, -1, -1, 1, 0, 1, 1, 0};

        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        dist[0][0] = 0;

        queue<pair<pair<int, int>, int>> q;
        q.push({{0,0} ,1});

        while(!q.empty()){
            auto ele = q.front();
            q.pop();
            int row = ele.first.first;
            int col = ele.first.second;

            int currdist = ele.second;

            for(int i=0;i<8;i++){
                int nr = row + drow[i];
                int nc = col + dcol[i];
                if(nr >=0 && nc >=0 && nr < n && nc < n && grid[nr][nc] != 1){
                    if(currdist + 1 < dist[nr][nc]){
                        if(nr == n-1 && nc == n-1) return currdist+1;
                        dist[nr][nc] = currdist + 1;
                        q.push({{nr,nc}, dist[nr][nc]});
                    }
                }
            }
        }

        return -1;
    }
};