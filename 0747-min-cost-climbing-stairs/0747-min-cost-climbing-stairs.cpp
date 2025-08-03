class Solution {
public:
    int mincost(int ind, vector<int>& cost, vector<int>& memo){
        if(ind >= cost.size()) return 0;

        if(memo[ind] != -1) return memo[ind];

        int l = mincost(ind+1, cost, memo);
        int h = mincost(ind+2, cost, memo);

        return memo[ind] = min(l, h) + cost[ind];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size() + 1, -1);

        int first = mincost(0, cost, dp);
        int second = mincost(1, cost, dp);

        return min(first, second);
    }
};