class Solution {
public:
    double dfs(const string& curr, const string& target,
               unordered_map<string, vector<pair<string, double>>>& graph,
               unordered_set<string>& visited) {
        if (graph.find(curr) == graph.end()) return -1.0;
        if (curr == target) return 1.0;
        visited.insert(curr);
        for (auto& [nei, weight] : graph[curr]) {
            if (visited.count(nei)) continue;
            double sub = dfs(nei, target, graph, visited);
            if (sub > 0) {
                return weight * sub;
            }
        }
        return -1.0;
    }

    vector<double> calcEquation(vector<vector<string>>& equations,
                                vector<double>& values,
                                vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string, double>>> graph;
        int n = equations.size();
        for (int i = 0; i < n; ++i) {
            const string& A = equations[i][0];
            const string& B = equations[i][1];
            double v = values[i];
            graph[A].push_back({B, v});
            graph[B].push_back({A, 1.0 / v});
        }

        vector<double> ans;
        for (auto& q : queries) {
            const string& C = q[0];
            const string& D = q[1];
            if (graph.find(C) == graph.end() || graph.find(D) == graph.end()) {
                ans.push_back(-1.0);
            } else {
                unordered_set<string> visited;
                double result = dfs(C, D, graph, visited);
                ans.push_back(result);
            }
        }
        return ans;
    }
};
