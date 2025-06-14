class DisjointSet {
public:
    vector<int> size, parent;
    DisjointSet(int n) {
        size.resize(n + 1);
        parent.resize(n + 1);

        for (int i = 0; i < n + 1; i++) {
            size[i] = 1;
            parent[i] = i;
        }
    }
    int findp(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findp(parent[node]);
    }
    void unionbysize(int u, int v) {
        int ult_u = findp(u);
        int ult_v = findp(v);

        if (ult_u == ult_v)
            return;

        if (size[ult_u] < size[ult_v]) {
            parent[ult_u] = ult_v;
            size[ult_v] += size[ult_u];
        } else {
            parent[ult_v] = ult_u;
            size[ult_u] += size[ult_v];
        }
    }
};
class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int maxi = INT_MIN;

        DisjointSet ds(n * m);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int row = i;
                int col = j;
                if (grid[row][col] == 0)
                    continue;

                int drows[] = {0, -1, 0, 1};
                int dcols[] = {-1, 0, 1, 0};

                for (int i = 0; i < 4; i++) {
                    int nr = row + drows[i];
                    int nc = col + dcols[i];

                    if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
                        if (grid[nr][nc] == 1) {
                            ds.unionbysize(row * m + col, nr * m + nc);
                        }
                    }
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int row = i;
                int col = j;
                if (grid[row][col] == 1)
                    continue;

                unordered_set<int> comp;
                int sum = 0;

                int drows[] = {0, -1, 0, 1};
                int dcols[] = {-1, 0, 1, 0};

                for (int i = 0; i < 4; i++) {
                    int nr = row + drows[i];
                    int nc = col + dcols[i];

                    if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
                        if (grid[nr][nc] == 1) {
                            comp.insert(ds.findp(nr * n + nc));
                        }
                    }
                }

                for (auto ele : comp) {
                    sum += ds.size[ele];
                }

                maxi = max(maxi, sum + 1);
            }
        }

        for (int i = 0; i < n * m; i++) {
            maxi = max(maxi, ds.size[ds.findp(i)]);
        }

        return maxi;
    }
};