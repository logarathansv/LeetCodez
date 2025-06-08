class Solution {
public:
    bool dfs(int node, vector<vector<int>>& graph, vector<int>& state) {
        if (state[node] != 0) return state[node] == 1;

        state[node] = -1;

        for (int neigh : graph[node]) {
            if (!dfs(neigh, graph, state)) return false;
        }

        state[node] = 1;
        return true;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> state(n, 0);
        vector<int> result;

        for (int i = 0; i < n; ++i) {
            if (dfs(i, graph, state)) {
                result.push_back(i);
            }
        }

        return result;
    }
};
