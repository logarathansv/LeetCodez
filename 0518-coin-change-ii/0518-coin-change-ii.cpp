class Solution {
public:
    int findways(int ind, vector<int>& coins, int tar, vector<vector<int>> &memo){
        if(ind == 0) return tar % coins[0] == 0;

        if(memo[ind][tar] != -1) return memo[ind][tar];

        int ntake = findways(ind-1, coins, tar, memo);
        int take = 0;

        if(coins[ind] <= tar) take = findways(ind, coins, tar - coins[ind], memo);

        return memo[ind][tar] = ntake + take;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();

        vector<vector<int>> memo(n, vector<int>(amount+1, -1));
        return findways(n-1, coins, amount, memo);
    }
};