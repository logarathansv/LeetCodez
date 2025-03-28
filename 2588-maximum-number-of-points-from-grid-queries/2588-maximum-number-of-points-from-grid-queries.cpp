class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int v = grid.size()*grid[0].size();

        vector<int> ans(queries.size(), 0);
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
        vector<pair<int, int>> oquery;
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        
        for(int i=0;i<queries.size();i++){
            oquery.push_back({queries[i] , i});
        }
        sort(oquery.begin(), oquery.end());
        
        vector<pair<int, int>> dir = {{0,1}, {1,0}, {0, -1},{-1, 0}};
        
        pq.push({grid[0][0],{0,0}});
        visited[0][0] = true;
        int ct = 0;
        for(auto [val, ind] : oquery){
            while(!pq.empty() && pq.top().first < val){
                auto [value, pos] = pq.top();
                pq.pop();
                int r = pos.first, c = pos.second;
                ct++; 
                for(int i=0;i<4;i++){
                    int newr = r + dir[i].first;
                    int newc = c + dir[i].second;

                    if(newr >= 0 && newc >= 0 && newr < grid.size() && newc < grid[0].size() 
                        && !visited[newr][newc]){
                            visited[newr][newc] = true;
                            pq.push({grid[newr][newc], {newr, newc}});
                        }
                }
            }
            ans[ind] = ct;
        }
        
        return ans;
    }
};