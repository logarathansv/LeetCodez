class Solution {
public:
    void findTarget(int ind, vector<int>&nums, int sum, int& ans, int target){
        if(ind >= nums.size()){
            if(sum == target) ans++;
            return;
        }
        findTarget(ind + 1, nums, sum+nums[ind], ans, target);
        findTarget(ind + 1, nums, sum-nums[ind], ans, target);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int ans = 0;
        findTarget(0, nums, 0, ans, target);
        return ans;
    }
};