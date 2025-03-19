class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ct = 0;
        for(int i=0;i<nums.size()-2;i++){
            if(nums[i] == 0){
                nums[i] = 1;
                nums[i+1] = nums[i+1] == 0 ? 1 : 0;
                nums[i+2] = nums[i+2] == 0 ? 1 : 0;
                ct++;
            }
        }
        for(auto num:nums){
            if(num == 0) return -1;
        }
        return ct;
    }
};