class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> mp(numCourses, 0);
        vector<vector<int>> adj(numCourses);
        vector<int> ans;

        for(auto pre: prerequisites){
            adj[pre[1]].push_back(pre[0]);
            mp[pre[0]]++;
        }

        queue<int> q;
        int ct = 0;

        for(int i=0;i<mp.size();i++){
            if(mp[i] == 0) {q.push(i);}
        }

        while(!q.empty()){
            int ele = q.front();
            q.pop();  
            ans.push_back(ele);

            for(auto neigh : adj[ele]){
                mp[neigh]--;
                if(mp[neigh] == 0) q.push(neigh);
            }
        }

        if(ans.size() != numCourses) return {};
        return ans;
    }
};