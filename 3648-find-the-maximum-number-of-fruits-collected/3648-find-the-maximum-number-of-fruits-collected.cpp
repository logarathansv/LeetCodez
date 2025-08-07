class Solution {
public:
    int n;

    int child1(vector<vector<int>>& fruits) {
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += fruits[i][i];
        }
        return ans;
    }

    int child2(vector<vector<int>>& fruits, int i, int j, vector<vector<int>>& dp) {
        if (i >= n || j < 0 || j >= n) return 0;
        if (i == j || i > j) return 0;
        if (i == n - 1 && j == n - 1) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        int bottomLeft = fruits[i][j] + child2(fruits, i + 1, j - 1, dp);
        int bottom = fruits[i][j] + child2(fruits, i + 1, j, dp);
        int bottomRight = fruits[i][j] + child2(fruits, i + 1, j + 1, dp);

        return dp[i][j] = max({bottomLeft, bottom, bottomRight});
    }

    int child3(vector<vector<int>>& fruits, int i, int j, vector<vector<int>>& dp) {
        if (i >= n || j < 0 || j >= n) return 0;
        if (i == j || i < j) return 0;
        if (i == n - 1 && j == n - 1) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        int right = fruits[i][j] + child3(fruits, i, j + 1, dp);
        int rightUp = fruits[i][j] + child3(fruits, i - 1, j + 1, dp);
        int rightDown = fruits[i][j] + child3(fruits, i + 1, j + 1, dp);

        return dp[i][j] = max({right, rightUp, rightDown});
    }

    int maxCollectedFruits(vector<vector<int>>& fruits) {
        n = fruits.size();

        int c1 = child1(fruits);

        vector<vector<int>> dp2(n, vector<int>(n, -1));
        vector<vector<int>> dp3(n, vector<int>(n, -1));

        int c2 = child2(fruits, 0, n - 1, dp2);
        int c3 = child3(fruits, n - 1, 0, dp3);

        return c1 + c2 + c3;
    }
};
