class Solution {
public:
    int lcs(int ind1, int ind2, string& text1, string& text2, vector<vector<int>>& memo){
        if(ind1 < 0 || ind2 < 0) return 0;

        if(memo[ind1][ind2] != -1) return memo[ind1][ind2];

        if(text1[ind1] == text2[ind2]) {
            return memo[ind1][ind2] = 1 + lcs(ind1-1, ind2-1, text1, text2, memo);
        }

        return memo[ind1][ind2] = max(lcs(ind1, ind2-1, text1, text2, memo), 
                        lcs(ind1-1, ind2, text1, text2, memo));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();

        vector<vector<int>> memo(n, vector<int>(m, -1));

        return lcs(n-1, m-1, text1, text2, memo);
    }
};