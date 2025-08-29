class Solution {
public:
    bool match(int i, int j, string& s, string& p, vector<vector<int>>& dp){
        if(i < 0 && j < 0) return true;
        if (i < 0) {
            for (int k = 0; k <= j; k++) {
                if (p[k] != '*') return false;
            }
            return true;
        }
        if (j < 0) return false;

        if(dp[i][j] != -1) return dp[i][j];

        int and_ = 1;
        if(p[j] == '?' || s[i] == p[j]) {
            and_ &= match(i-1, j-1, s, p, dp);
        } else if(p[j] == '*'){
            and_ &= (match(i-1, j, s, p, dp) || match(i-1, j-1, s, p, dp)
                        || match(i, j-1, s, p, dp));
        } else return false;

        return dp[i][j] = and_;
    }
    bool isMatch(string s, string p) {
        if(s == p || p == "*") return true;
        int n = s.size();
        int m = p.size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        return match(n-1, m-1, s, p, dp);
    }
};