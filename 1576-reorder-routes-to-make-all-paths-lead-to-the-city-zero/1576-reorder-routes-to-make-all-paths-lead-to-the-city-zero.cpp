class Solution {
public:
    int ct = 0;

    void dfs(int node, unordered_set<string>& connst, vector<vector<int>>& adj, vector<bool>& vis){
        vis[node] = true;

        for(auto neigh : adj[node]){
            if(!vis[neigh]){ 
                if(connst.find(to_string(neigh)+"+"+to_string(node)) == connst.end()) ct++;
                dfs(neigh, connst, adj, vis);
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        vector<bool> vis(n, false);

        unordered_set<string> connst;

        for(auto edge:connections){
            connst.insert(to_string(edge[0])+"+"+to_string(edge[1]));
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        dfs(0, connst, adj, vis);

        return ct;
    }
};