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
    int removeStones(vector<vector<int>>& stones) {
        int maxr = 0, maxc = 0;
        for(auto i:stones){
            maxr = max(maxr, i[0]);
            maxc = max(maxc, i[1]);
        }
        DisjointSet ds(maxr + maxc + 1);
        unordered_map<int, int> mp;

        for(auto i:stones){
            int u = i[0];
            int v = i[1] + maxr + 1;
            ds.unionbysize(u, v);
            mp[u] = 1;mp[v] = 1;
        }
        int ct = 0;
        for(auto i : mp){
            if(ds.findp(i.first) == i.first) ct++;
        }

        return stones.size() - ct;
    }
};