class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        dist[0][0] = 0;

        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> q;
        q.push({0, {0,0}});

        int drow[] = {0, 1, 0, -1};
        int dcol[] = {1, 0, -1, 0};

        while(!q.empty()){
            auto ele = q.top();
            q.pop();
            int row = ele.second.first;
            int col = ele.second.second;

            int dep = ele.first;

            if(row == n-1 && col == m-1) return dep;

            for(int i=0;i<4;i++){
                int nr = row + drow[i];
                int nc = col + dcol[i];
                
                if(nr >= 0 && nc >= 0 && nr < n && nc < m ){
                    int currdiff = abs(heights[nr][nc] - heights[row][col]);
                    int maxi = max(currdiff, dep);

                    if(maxi < dist[nr][nc]){
                        dist[nr][nc] = maxi;

                        q.push({dist[nr][nc], {nr, nc}});
                    }
                    
                }
            }
        }

        return 0;
    }
};