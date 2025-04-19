class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long ans = 0;
        int n = nums.size();

        sort(nums.begin(), nums.end());
        for(int i=0;i<nums.size();i++){
            int lo = lower - nums[i];
            int hi = upper - nums[i];

            int indlo = lower_bound(nums.begin() + i + 1, nums.end(), lo) - nums.begin();
            int indup = upper_bound(nums.begin() + i + 1, nums.end(), hi) - nums.begin();

            ans += indup - indlo;
        }

        return ans;
    }
};