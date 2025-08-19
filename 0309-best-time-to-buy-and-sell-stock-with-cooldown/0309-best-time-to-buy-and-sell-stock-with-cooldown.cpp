class Solution {
public:
    int buyStock(int ind, int buy, vector<int>& prices, vector<vector<int>>& dp){
        if(ind >= prices.size()) return 0;

        if(dp[ind][buy] != -1) return dp[ind][buy];
        int profit = 0;
        if(buy){
            profit = max(-prices[ind] + buyStock(ind + 1, 0, prices, dp),
                            buyStock(ind + 1, 1, prices, dp));
        } else{
            profit = max(prices[ind] + buyStock(ind + 2, 1, prices, dp),
                            buyStock(ind + 1, 0, prices, dp));
        }

        return dp[ind][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(2, -1));

        return buyStock(0, 1, prices, dp);
    }
};