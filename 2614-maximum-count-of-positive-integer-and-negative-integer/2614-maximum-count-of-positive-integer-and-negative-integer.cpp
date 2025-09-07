class Solution {
public:
    int maximumCount(vector<int>& nums) {
        auto p = upper_bound(nums.begin(), nums.end(), 0);
        int pos = distance(p, nums.end());
        auto n = lower_bound(nums.begin(), nums.end(), 0);
        int neg = distance(nums.begin(), n);

        return max(pos, neg);
    }
};