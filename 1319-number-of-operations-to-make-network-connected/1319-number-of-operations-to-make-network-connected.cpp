class DisjointSet {
public:
    vector<int> par, size;

    DisjointSet(int n){
        par.resize(n);
        size.resize(n, 1);
        for(int i=0;i<n;i++) par[i] = i;
    }
    int findpar(int node){
        if(par[node] == node) return node;
        return par[node] = findpar(par[node]);
    }
    void unionbysize(int u, int v){
        int ultu = findpar(u);
        int ultv = findpar(v);
        if(ultu == ultv) return;
        if(size[ultu] < size[ultv]){
            size[ultv] += size[ultu];
            par[ultu] = ultv;
        } else {
            size[ultu] += size[ultv];
            par[ultv] = ultu;
        }
    }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(n - 1 > connections.size()) return -1;
        DisjointSet ds(n);

        int ct = 0, compo = 0;
        for(int i=0;i<connections.size();i++){
            int u = connections[i][0];
            int v = connections[i][1];
            if(ds.findpar(u) == ds.findpar(v)) ct++;
            else ds.unionbysize(connections[i][0], connections[i][1]);
        }

        for(int i=0;i<n;i++) if(ds.findpar(i) == i) compo++;

        return ct >= compo - 1 ? compo - 1 : -1;
    }
};