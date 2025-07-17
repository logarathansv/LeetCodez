class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        vector<vector<int>> dp(k, vector<int>(k, 0));
        int res = INT_MIN;
        for(int num : nums){
            int mod = num%k;
            for(int prev=0;prev<k;prev++){
                dp[mod][prev] = dp[prev][mod] + 1;
                res = max(res, dp[mod][prev]);
            }
        }

        return res;
    }
};