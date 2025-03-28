class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxi = INT_MIN;
        int sum = 0;
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
            if(sum > maxi){
                maxi = sum;
            }
            if(sum < 0){
                sum = 0;
            }
        }
        sum = 0;
        int mini = INT_MAX;
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
            if(sum < mini){
                mini = sum;
            }
            if(sum > 0){
                sum = 0;
            }
        }
        return max(maxi, abs(mini));
    }
};