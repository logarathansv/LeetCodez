class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int pos = 0, neg = 0;
        for(auto num:nums) (num > 0) ? pos++ : neg += (num < 0) ? 1 : 0;
        return max(pos, neg);
    }
};