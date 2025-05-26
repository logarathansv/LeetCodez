class Solution {
public:
    int dfs(int& node, vector<vector<int>> &adj, vector<vector<int>> &ct, vector<int> &vis, string& colors){
        if(!vis[node]){
            vis[node] = 1;
            for(auto neigh:adj[node]){
                if(dfs(neigh, adj, ct, vis, colors) == INT_MAX)
                    return INT_MAX;
                for(int i=0;i<26;i++){
                    ct[node][i] = max(ct[node][i], ct[neigh][i]);
                }
            }
            ct[node][colors[node] - 'a']++;
            vis[node] = 2;
        }
        return vis[node] != 2 ? INT_MAX : ct[node][colors[node] - 'a'];
    }
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<vector<int>> adj(n);
        vector<vector<int>> ct(n, vector<int> (26));
        vector<int> visited(n, 0);

        int ans = 0;
        for(auto edge:edges){
            adj[edge[0]].push_back(edge[1]);
        }

        for(int i=0;i<n && ans != INT_MAX;i++){
            ans = max(ans, dfs(i, adj, ct, visited, colors));
        }

        return ans == INT_MAX ? -1 : ans;
    }   
};