class Solution {
public:
    int numsub(vector<int>& nums, int goal){
        if(goal < 0) return 0;
        int sum = 0, ct = 0, l =0;

        for(int i=0;i<nums.size();i++){
            sum += nums[i];
            while(sum > goal && l < nums.size()){
                sum -= nums[l++];
            }
            ct += (i-l+1);
        }

        return ct;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return numsub(nums, goal) - numsub(nums, goal-1);
    }
};