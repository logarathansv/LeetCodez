class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        
        int val = 0;
        vector<int> prev(m+1, 0);
        vector<int> dp(m+1, 0);

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(word1[i-1] == word2[j-1]){
                    dp[j] = 1+ prev[j-1];
                } else dp[j] = max(prev[j], dp[j-1]);
            }
            prev = dp;
        }

        val = prev[m];

        return n - val + m - val;
    }
};