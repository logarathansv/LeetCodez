class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

        dist[0][0] = 0;

        pq.push({grid[0][0], {0,0}});
        
        while(!pq.empty()){
            auto ele = pq.top();
            pq.pop();

            int wt = ele.first;
            int row = ele.second.first;
            int col = ele.second.second;

            if(row == n-1 && col == n-1) return wt;

            int drow[] = {0, -1, 0, 1};
            int dcol[] = {-1, 0, 1, 0};

            for(int i=0;i<4;i++){
                int nr = row + drow[i];
                int nc = col + dcol[i];

                if(nr >=0 && nc >=0 && nr < n && nc < n){
                    if(dist[nr][nc] != INT_MAX) continue;
                    int maxi = max(grid[nr][nc], wt);
                    if(maxi < dist[nr][nc]){
                        
                        dist[nr][nc] = maxi;
                        cout<<"r"<<nr<<"c"<<nc<<"dist"<<dist[nr][nc]<<'\n';

                        pq.push({dist[nr][nc], {nr, nc}});
                    }
                }
            }
        }

        return -1;
    }
};