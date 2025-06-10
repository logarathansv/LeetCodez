class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int maxi = INT_MIN;
        vector<vector<pair<int, int>>> adj(n + 1);
        for(auto time: times){
            adj[time[0]].push_back({time[1], time[2]});
        }

        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});

        while(!pq.empty()){
            auto ele = pq.top();
            pq.pop();
            int weigh = ele.first;
            int node = ele.second;

            for(auto neigh : adj[node]){
                if(neigh.second + weigh < dist[neigh.first]){
                    dist[neigh.first] = neigh.second + weigh;

                    pq.push({dist[neigh.first], neigh.first});
                }
            }
        }

        for(int i = 1;i < dist.size();i++) {
            if(dist[i] == INT_MAX) return -1;
            maxi = max(dist[i], maxi);
        }

        return maxi;
    }
};