class Solution {
public:
    void findSubset(int ind, vector<int>& temp, vector<int>& nums, int mxor, int &ans){
        if(ind == nums.size()){
            int check = 0;
            for(auto num:temp){
                check = check | num;
            }
            if(check == mxor) ans++;
            return;
        }
        temp.push_back(nums[ind]);
        findSubset(ind+1, temp, nums, mxor, ans);
        temp.pop_back();
        findSubset(ind+1, temp, nums, mxor, ans);
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int mxor = 0;
        for(auto num:nums){
            mxor = mxor | num;
        }
        vector<int> temp;
        int res = 0;
        findSubset(0, temp, nums, mxor, res);
        return res;
    }
};