class Solution {
public:
    void dfs(int node, vector<int>& edges, vector<int>& vis, vector<int>& dis){
        vis[node] = true;

        int neigh = edges[node];
        if(neigh != -1 && !vis[neigh]){
            dis[neigh] = 1 + dis[node];
            dfs(neigh, edges, vis, dis);
        }
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();

        vector<int> dis1(n, INT_MAX);
        vector<int> dis2(n, INT_MAX);

        dis1[node1] = 0; dis2[node2] = 0;

        vector<int> vis(n, false);
        vector<int> vis2(n, false);

        int maxi = -1, mini = INT_MAX;

        dfs(node1, edges, vis, dis1);
        dfs(node2, edges, vis2, dis2);
        
        for(int i=0;i<n;i++){
            if(mini > max(dis1[i], dis2[i])){
                maxi = i;
                mini = max(dis1[i], dis2[i]);
            }
        }

        return maxi;
    }
};