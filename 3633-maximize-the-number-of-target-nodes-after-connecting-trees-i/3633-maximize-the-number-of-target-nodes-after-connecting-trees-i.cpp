class Solution {
public:
    int nodes = 0;
    void dfs(int node, vector<vector<int>> &adj, vector<bool> &vis, int k, int ct){
        if(k < 0) return;
        if(ct >= k) return;

        vis[node] = 1;
        for(auto neigh: adj[node]){
            if(!vis[neigh]){
                nodes++;
                dfs(neigh, adj, vis, k, ct + 1);
            }
        }
    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        if(k == 0) {
            vector<int> ans;
            for(int i=0;i<edges1.size()+1;i++) ans.push_back(1);
            return ans;
        }

        vector<vector<int>> adj1(edges1.size() + 1);
        vector<vector<int>> adj2(edges2.size() + 1);

        vector<int> dist1(edges1.size() + 1);
        vector<int> dist2(edges2.size() + 1);

        vector<int> ans;
        int maxi = 0;

        for(auto edge:edges1){
            adj1[edge[0]].push_back(edge[1]);
            adj1[edge[1]].push_back(edge[0]);
        }

        for(auto edge:edges2){
            adj2[edge[0]].push_back(edge[1]);
            adj2[edge[1]].push_back(edge[0]);
        }    

        for(int i=0;i<edges1.size()+1;i++){
            vector<bool> vis(edges1.size() + 1);

            dfs(i, adj1, vis, k, 0);
            dist1[i] = nodes + 1;
            nodes = 0;
        }

        for(int i=0;i<edges2.size()+1;i++){
            vector<bool> vis2(edges2.size() + 1);

            dfs(i, adj2, vis2, k-1, 0);
            maxi = max(nodes + 1, maxi);
            nodes = 0;
        }

        for(int i=0;i<edges1.size() + 1;i++){
            ans.push_back(dist1[i] + maxi);
        }

        return ans;
    }
};