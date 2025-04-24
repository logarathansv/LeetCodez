class Solution {
public:
    void dfs(int node, vector<int> &visited, vector<vector<int>>& adj){
        visited[node] = true;

        for(auto neigh : adj[node]){
            if(!visited[neigh]) dfs(neigh, visited, adj);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size(), ct = 0;
        vector<vector<int>> adj(n);
        vector<int> visited(n + 1, false);

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j] == 1){
                    adj[j].push_back(i);
                    adj[i].push_back(j);
                }
            }
        }

        for(int i=0;i<n;i++){
            if(!visited[i]) {ct++;dfs(i, visited, adj);}
        }

        return ct;
    }
};