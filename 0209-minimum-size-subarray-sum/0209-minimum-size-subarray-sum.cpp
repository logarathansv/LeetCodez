class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0, sum = 0, mini = INT_MAX, len = 0;

        for(int r=0;r<nums.size();r++){
            sum += nums[r];

            while(sum >= target){
                len = r-l+1;
                mini = min(len, mini);
                sum -= nums[l++];
            }    
        }

        return mini == INT_MAX ? 0 : mini;
    }
};