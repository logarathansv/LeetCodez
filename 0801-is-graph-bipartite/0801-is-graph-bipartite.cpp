class Solution {
public:
    bool dfs(int node, vector<int>& vis, vector<vector<int>>& graph, bool flag){
        if(flag) vis[node] = 1;
        else vis[node] = -1;

        for(auto neigh : graph[node]){
            if(vis[neigh] == vis[node]) return false;
            else if(vis[neigh] == 0){
                return dfs(neigh, vis, graph, !flag);
            }
        }

        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        for(int i=0;i<graph.size();i++){
            vector<int> vis(graph.size(), 0);
            if(!vis[i]){
                if(!dfs(i, vis, graph, 0)) return false;
            }
        }

        return true;
    }
};