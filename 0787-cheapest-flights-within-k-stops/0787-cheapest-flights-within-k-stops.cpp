class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto flight : flights) {
            adj[flight[0]].emplace_back(flight[1], flight[2]);
        }

        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        queue<vector<int>> q;
        q.push({0, src, 0});

        while(!q.empty()){
            auto ele = q.front();q.pop();

            int dis = ele[0];
            int node = ele[1];
            int takek = ele[2];
           
            // if(node == dst) return dis;
            if(takek > k) continue;
            for(auto i:adj[node]){
                int neigh = i.first;
                int edgewt = i.second;
                if(dis + edgewt < dist[neigh]){
                    dist[neigh] = dis + edgewt;
                     cout<<dist[neigh]<<" "<<neigh<<" "<<takek<<'\n';
                    
                    q.push({dist[neigh], neigh, takek+1});
                }
            }
        }

        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};