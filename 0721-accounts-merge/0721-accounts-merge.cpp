class DisjointSet{
public:
    vector<int> size, parent;
    DisjointSet(int n){
        size.resize(n+1);
        parent.resize(n+1);

        for(int i=0;i<n+1;i++) {
            size[i] = 1;
            parent[i] = i;
        }
    }
    int findp(int node){
        if(node == parent[node]) return node;
        return parent[node] = findp(parent[node]);
    }
    void unionbysize(int u, int v){
        int ult_u = findp(u);
        int ult_v = findp(v);

        if(ult_u == ult_v) return;
        
        if(size[ult_u] < size[ult_v]){
            parent[ult_u] = ult_v;
            size[ult_v] += size[ult_u];
        }
        else{
            parent[ult_v] = ult_u;
            size[ult_u] += size[ult_v];
        }
    }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, int> mp;
        DisjointSet ds(accounts.size());

        for(int i=0;i<accounts.size();i++){
            for(int j=1;j<accounts[i].size();j++){
                if(mp.find(accounts[i][j]) != mp.end()){
                    ds.unionbysize(i, mp[accounts[i][j]]);
                    accounts[i][j] = "";
                }
                else mp[accounts[i][j]] = i;
            }
        }

        vector<vector<string>> ans(accounts.size());

        for(int i=0;i<accounts.size();i++) {
            string name = accounts[i][0];
            ans[i].push_back(name);
        }

        for(int i=0;i<accounts.size();i++){
            for(int j=1;j<accounts[i].size();j++){
                if(accounts[i][j] == "") continue;
                int ultp = ds.findp(mp[accounts[i][j]]);
                if(ultp == mp[accounts[i][j]]){
                    ans[i].push_back(accounts[i][j]);
                }
                else ans[ultp].push_back(accounts[i][j]);
            }
        }

        vector<vector<string>> res;

        for(int i=0;i<accounts.size();i++){
            if(ans[i].size() == 1) {continue;}
            sort(ans[i].begin() + 1, ans[i].end());
            res.push_back(ans[i]);
        }

        return res;
    }
};