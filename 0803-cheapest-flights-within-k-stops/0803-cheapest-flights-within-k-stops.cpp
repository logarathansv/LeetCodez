class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (const auto& flight : flights) {
            adj[flight[0]].emplace_back(flight[1], flight[2]);
        }

        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        queue<vector<int>> q;
        q.push({0, src, 0});

        while(!q.empty()){
            auto it = q.front();
            q.pop();

            int dis = it[0];
            int node = it[1];
            int step = it[2];

            if(step > k) continue; 

            for(auto neigh : adj[node]){
                if(neigh.second + dis < dist[neigh.first] && step <= k){
                    dist[neigh.first] = neigh.second + dis;

                    q.push({dist[neigh.first], neigh.first, step+1});
                }
            }

        }

        if (dist[dst] == INT_MAX)
            return -1;
        return dist[dst];

    }
};