class DisjointSet{
public:
    vector<int> rank, parent;
    DisjointSet(int v){
        rank.resize(v+1);
        parent.resize(v+1); 

        for(int i=0;i<v;i++) {parent[i] = i;rank[i] = 0;}
    }
    int findP(int node){
        if(node == parent[node]) return node;
        return parent[node] = findP(parent[node]);
    }
    void unionbyrank(int u, int v){
        int ult_u = findP(u);
        int ult_v = findP(v);
        if(ult_u == ult_v) return;
        if(rank[ult_u] < rank[ult_v]){
            parent[ult_u] = ult_v;
        }
        else if(rank[ult_v] < rank[ult_u]){
            parent[ult_v] = ult_u;
        }
        else{
            parent[ult_v] = ult_u;
            rank[ult_u]++;
        }
    }
};

class Solution {
public:    
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<bool> vis(n, false);

        int ct = 0, ct2 = 0;

        DisjointSet ds(n);
        
        for(auto ele:connections){
            int u = ele[0];
            int v = ele[1];

            int ult_u = ds.findP(u);
            int ult_v = ds.findP(v);

            if(ult_u == ult_v){
                ct++;
            }
            else ds.unionbyrank(u, v);
        }

        for(int i=0;i<n;i++) if(ds.parent[i] == i) ct2++;

        if(ct >= ct2-1) return ct2-1;
        return -1;
    }
};