class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return {};
        int N = matrix.size(), M = matrix[0].size();
        vector<int> result(N * M);
        int k = 0;
        vector<int> intermediate;
        for (int d = 0; d < N + M - 1; d++) {
            intermediate.clear();
            int r = (d < M) ? 0 : d - M + 1;
            int c = (d < M) ? d : M - 1;
            while (r < N && c >= 0) {
                intermediate.push_back(matrix[r][c]);
                r++;
                c--;
            }
            if (d % 2 == 0) reverse(intermediate.begin(), intermediate.end());
            for (int val : intermediate) result[k++] = val;
        }
        return result;
    }
};
