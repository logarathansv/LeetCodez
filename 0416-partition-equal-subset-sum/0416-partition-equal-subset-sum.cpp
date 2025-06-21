class Solution {
public:
    bool possible(int target, int ind, vector<int>& nums, vector<vector<int>> &memo){
        if(target == 0) return true;
        if(ind == 0) return nums[0] == target;

        if(memo[ind][target] != -1) return memo[ind][target];

        bool nott = possible(target, ind-1, nums, memo);

        bool take = false;
        if(nums[ind] <= target) take = possible(target - nums[ind], ind-1, nums, memo);

        memo[ind][target] = nott || take;

        return memo[ind][target]; 
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for (int num : nums) {
            sum += num;
        }
        if (sum % 2 != 0) {
            return false;
        }

        vector<vector<int>> memo(n, vector<int>(sum/2 + 1, -1));

        return possible(sum/2, n-1, nums, memo);        
    }
};