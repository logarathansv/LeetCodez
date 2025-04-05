class Solution {
public:
    void subset(int ind, int ct, int& sum, vector<int>& nums){
        if(ind == nums.size()) {
            sum += ct;
            return;
        }
        subset(ind + 1, ct, sum, nums);
        subset(ind + 1, ct ^ nums[ind], sum, nums);
    }
    int subsetXORSum(vector<int>& nums) {
        int sum = 0;
        subset(0, 0, sum, nums);
        return sum;
    }
};