class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indeg(numCourses, 0);

        for(auto i:prerequisites){
            adj[i[1]].push_back(i[0]);
            indeg[i[0]]++;
        }

        queue<int> q;

        for(int i=0;i<numCourses;i++){
            if(indeg[i] == 0){ q.push(i);cout<<i;}
        }

        int ct = 0;
        while(!q.empty()){
            int node = q.front();q.pop();
            ct++;
            for(auto neigh : adj[node]){
                indeg[neigh]--;
                if(indeg[neigh] == 0){
                    q.push(neigh);
                }
            }
        }

        // for(int i=0;i<V;i++){
        //     for(auto neigh:adj[i]) indeg[neigh]++
        // }

        return ct == numCourses;
    }
};