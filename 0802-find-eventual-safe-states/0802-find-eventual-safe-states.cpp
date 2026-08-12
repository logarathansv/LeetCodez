class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<vector<int>> adj(graph.size());
        vector<int> indeg(graph.size(), 0);

        queue<int> q;
        for(int i=0;i<graph.size();i++){
            for(auto neigh : graph[i]){
                adj[neigh].push_back(i);
                indeg[i]++;
            }
        }

        for(int i=0;i<graph.size();i++){
            if(indeg[i] == 0) q.push(i);
        }

        vector<int> ans;
        while(!q.empty()){
            int node = q.front();q.pop();
            ans.push_back(node);

            for(auto i:adj[node]){
                indeg[i]--;
                if(indeg[i] == 0) q.push(i);
            }
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};