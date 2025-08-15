class Solution {
public:
    int mini(int i, int j, string &w1, string &w2, vector<vector<int>> &dp){
        if(i < 0) return j+1;
        else if(j < 0) return i + 1;

        if(dp[i][j] != -1) return dp[i][j];

        if(w1[i] == w2[j]) {
            dp[i][j] =  mini(i-1, j-1, w1, w2, dp);
        }
        else{
            dp[i][j] = 1 + min({
                mini(i, j-1, w1, w2, dp),
                mini(i-1, j, w1, w2, dp),
                mini(i-1, j-1, w1, w2, dp),
            });
        }

        return dp[i][j];
    } 
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        
        return mini(n-1, m-1, word1, word2, dp);
    }
};