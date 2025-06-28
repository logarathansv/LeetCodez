class Solution {
public:
    int findway(int ind, int sum, vector<int>& arr, vector<vector<int>>& memo){
        if(ind == 0){
            if(sum == 0 && arr[0] == 0) return 2;
            return (arr[0] == sum || sum == 0) ? 1 : 0;
        }

        if(memo[ind][sum] != -1) return memo[ind][sum];

        int notp = findway(ind-1, sum, arr, memo);
        int p = 0;

        if(arr[ind] <= sum) p = findway(ind-1, sum-arr[ind], arr, memo);

        memo[ind][sum] = notp + p;

        return memo[ind][sum];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0;

        for(auto num:nums) sum += num;

        if((sum - target) < 0 || (sum - target)%2) return 0;

        vector<vector<int>> memo(n, vector<int>((sum-target)/2 + 1, -1));

        return findway(n-1, (sum - target)/2, nums, memo);
    }
};