class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dis(n+1, 1e9);
        dis[k] = 0;
        vector<pair<int, int>> adj[n+1];

        for(auto i:times){
            adj[i[0]].push_back({i[1], i[2]});
        }

        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, k});

        while(!pq.empty()){
            auto ele = pq.top();pq.pop();

            int dist = ele.first;
            int node = ele.second;

            for(auto neigh:adj[node]){
                int neighnode = neigh.first;
                int cost = neigh.second;

                if(dis[neighnode] > dist + cost){
                    dis[neighnode] = dist + cost;
                    pq.push({dis[neighnode], neighnode});
                }
            }
        }
        int maxi = INT_MIN, ct = 0;
        for(auto i:dis){
            if(i != 1e9) {maxi=max(maxi, i);}
            else ct++;
            if(ct > 1) return -1;
        }

        return maxi;
    }
};