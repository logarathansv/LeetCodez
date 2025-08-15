class Solution {
public:
    int mini(int i, int j, string& w1, string& w2, vector<vector<int>>& dp) {
        if (i < 0)
            return j + 1;
        else if (j < 0)
            return i + 1;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (w1[i] == w2[j]) {
            dp[i][j] = mini(i - 1, j - 1, w1, w2, dp);
        } else {
            dp[i][j] = 1 + min({
                               mini(i, j - 1, w1, w2, dp),
                               mini(i - 1, j, w1, w2, dp),
                               mini(i - 1, j - 1, w1, w2, dp),
                           });
        }

        return dp[i][j];
    }
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<int> dp(m + 1, -1);

        for(int i=0;i<=m;i++) dp[i] = i;

        for (int i = 1; i <= n; i++) {
            vector<int> temp(m + 1, -1);
            temp[0] = i;
            for (int j = 1; j <= m; j++) {

                if (word1[i-1] == word2[j-1]) {
                    temp[j] = dp[j - 1];
                } else {
                    temp[j] = 1 + min({
                                       dp[j],
                                       temp[j - 1],
                                       dp[j - 1],
                                   });
                }
            }
            dp = temp;
        }

        return dp[m];

        // return mini(n-1, m-1, word1, word2, dp);
    }
};