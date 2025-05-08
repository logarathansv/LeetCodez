class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size();
        int m = moveTime[0].size();

        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        dist[0][0] = 0;

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({0, {0,0}});
        int j = 1;

        while(!pq.empty()){
            int t = pq.top().first;
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            pq.pop();

            if(r == n-1 && c == m-1) return t;
            
            int rows[] = {-1, 0, 1, 0};
            int cols[] = {0, 1, 0, -1};

            for(int i = 0;i < 4;i++){
                int nr = r + rows[i];
                int nc = c + cols[i];

                if(nr >=0 && nr < n && nc >=0 && nc < m){
                    j = (r + c)%2 + 1;
                    int diff = max(t, moveTime[nr][nc]) + j;

                    if(diff < dist[nr][nc]){
                        dist[nr][nc] = diff;
                        pq.push({diff, {nr, nc}});
                    }
                }
            }
        }
        return -1;
    }
};