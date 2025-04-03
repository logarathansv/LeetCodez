class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long ans = nums[0];
        long long maxdiff = 0;
        long long maxval;
        for(int i=1;i<nums.size();i++){
             maxval = max(maxval, maxdiff * nums[i]);
            maxdiff = max(maxdiff, ans - nums[i]);
            ans = max(ans, (long long)nums[i]);
        }
        return maxval;
    }
};