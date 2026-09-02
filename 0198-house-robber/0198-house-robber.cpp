class Solution {
public:
    int robb(int ind, vector<int>& nums, vector<int>& dp){
        if(ind < 0) return 0;
        if(ind == 0) return nums[ind];

        if(dp[ind] != -1) return dp[ind];

        int take = nums[ind] + robb(ind-2, nums, dp);
        int ntake = robb(ind-1, nums, dp);

        return dp[ind] = max(take, ntake);
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return robb(nums.size()- 1, nums, dp);
    }
};