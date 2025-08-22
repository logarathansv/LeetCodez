class Solution {
public:
    int longest(int ind, int prev, vector<int>& nums, vector<vector<int>>& dp){
        if(ind == nums.size()) return 0;
        
        if(dp[ind][prev + 1] != -1) return dp[ind][prev+1];

        int take = 0, skip = 0;
        if(prev == -1 || nums[prev] < nums[ind]){
            take = longest(ind + 1, ind, nums, dp) + 1;
        }
        skip = longest(ind + 1, prev, nums, dp);

        return dp[ind][prev + 1] = max(take, skip);
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size() + 1, -1));

        return longest(0, -1, nums, dp);
    }
};