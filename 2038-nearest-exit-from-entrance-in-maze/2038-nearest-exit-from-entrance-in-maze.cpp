class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n = maze.size();
        int m = maze[0].size();

        int mini = INT_MIN;

        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        dist[entrance[0]][entrance[1]] = 0;
        queue<pair<pair<int, int>, int>> pq;

        int drows[] = {-1, 0, 1, 0};
        int dcols[] = {0, 1, 0, -1};

        pq.push({{entrance[0], entrance[1]}, 0});
        
        while(!pq.empty()){
            auto ele = pq.front();
            pq.pop();

            int wt = ele.second;
            int r = ele.first.first;
            int c = ele.first.second;

            if((r == 0 || r == n-1 || c == 0 || c == m-1) && !(r == entrance[0] && c == entrance[1]))
                return wt;

            for(int i=0;i<4;i++){
                int nr = r + drows[i];
                int nc = c + dcols[i];

                if(nr >= 0 && nc >= 0 && nr < n && nc < m && maze[nr][nc] == '.'){  
                    if(wt + 1 < dist[nr][nc]){
                        dist[nr][nc] = wt+1;
                        pq.push({{nr, nc}, wt+1});
                    }
                }
            }
        }

        return -1;
    }
};