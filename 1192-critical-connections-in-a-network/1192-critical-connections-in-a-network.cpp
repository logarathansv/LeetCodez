class Solution {
public:
    int t = 0;
    void dfs(int node, int par, vector<vector<int>>& bridges, vector<int>& tm, vector<int>& low, vector<bool> &vis, vector<int> adj[]){
        vis[node] = 1;
        tm[node] = low[node] = t++;

        for(auto it:adj[node]){
            if(it == par) continue;
            if(vis[it] == 0){
                dfs(it, node, bridges, tm, low, vis, adj);
                low[node] = min(low[node], low[it]);
                if(tm[node] < low[it]) bridges.push_back({node, it});
            } else{
                low[node] = min(low[node], low[it]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> adj[n];

        for(auto i:connections){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }

        vector<bool> vis(n, 0);
        vector<int> tm(n);
        vector<int> low(n);
        vector<vector<int>> bridges;

        dfs(0, -1, bridges, tm, low, vis, adj);

        return bridges;
    }
};