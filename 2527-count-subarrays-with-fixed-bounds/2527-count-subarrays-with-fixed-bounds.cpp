class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int maxi = -1, mini = -1, badi = -1;
        long long ans = 0;

        for(int i=0;i<nums.size();i++){
            if(nums[i] == maxK) maxi = i;
            if(nums[i] == minK) mini = i;
            if(!(minK <= nums[i] && nums[i] <= maxK)) badi = i;

            ans += max(0, min(mini, maxi) - badi);
        }

        return ans;
    }
};