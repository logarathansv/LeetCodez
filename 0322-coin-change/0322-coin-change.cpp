class Solution {
public:
    int change(int ind, int amt, vector<int>& coins, vector<vector<int>> &memo){
        if(ind == 0){
            if(amt % coins[ind] == 0) return amt / coins[ind];

            return 1e9;
        }

        if(memo[ind][amt] != -1) return memo[ind][amt];

        int nott = change(ind-1, amt, coins, memo);
        int take = INT_MAX;

        if(coins[ind] <= amt) take = 1 + change(ind, amt - coins[ind], coins, memo);
    
        return memo[ind][amt] = min(nott, take);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();

        vector<vector<int>> memo(n, vector<int>(amount+1, -1));

        int ans = change(n-1, amount, coins, memo);

        if(ans >= 1e9) return -1;

        return ans;
        

        // vector <int> dp(amount+1,amount+1);
        // dp[0] = 0;
        // for(auto coin:coins){
        //     for(int i=coin;i<amount+1;i++){
        //         dp[i] = min(dp[i],dp[i-coin]+1);
        //     }

        // }
        
        // return dp[amount] > amount ? -1 : dp[amount];
    }
};