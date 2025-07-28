class Solution {
public:
    void findSubset(int ind, int check, vector<int>& nums, int mxor, int &ans){
        if(ind == nums.size()){
            if(check == mxor) ans++;
            return;
        }
        findSubset(ind+1, check | nums[ind], nums, mxor, ans);
        findSubset(ind+1, check, nums, mxor, ans);
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int mxor = 0;
        for(auto num:nums){
            mxor = mxor | num;
        }
        vector<int> temp;
        int res = 0;
        findSubset(0, 0, nums, mxor, res);
        return res;
    }
};