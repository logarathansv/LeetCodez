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
        int ans = 1, maxrow = INT_MIN, maxcol = INT_MIN, ct = 0;
        for(int i=0;i<stones.size();i++){
            maxrow = max(stones[i][0], maxrow);
            maxcol = max(stones[i][1], maxcol);
        }
        DisjointSet ds(maxrow + maxcol + 1);
        unordered_map<int, int> mp;
        for(int i=0;i<stones.size();i++){
            ds.unionbysize(stones[i][0], stones[i][1] + maxrow + 1);
            mp[stones[i][0]] = 1;
            mp[stones[i][1] + maxrow + 1] = 1;
        }
        for(auto ele : mp){
            if(ds.findp(ele.first) == ele.first) ct++;
        }
        return stones.size() - ct;
    }
};