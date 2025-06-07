class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, int> mp;
        vector<vector<int>> adj(numCourses);

        for(auto pre: prerequisites){
            adj[pre[0]].push_back(pre[1]);
        }

        for(int i=0;i<numCourses;i++) mp[i] = 0;
        for(int i=0;i<numCourses;i++){
            for(auto neigh : adj[i]){
                mp[neigh]++;
            }
        }

        queue<int> q;
        int ct = 0;

        for(auto ele: mp){
            if(ele.second == 0) {q.push(ele.first);}
        }

        while(!q.empty()){
            int ele = q.front();
            q.pop();  
            ct++;

            for(auto neigh : adj[ele]){
                mp[neigh]--;
                if(mp[neigh] == 0) q.push(neigh);
            }
        }

        if(ct != numCourses) return false;
        return true;
    }
};