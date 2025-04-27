class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int sum = 0;
        
        for(int i=0;i+2<nums.size();i++){
            if(nums[i] + nums[i+2] == (float)nums[i+1]/2) sum++;
        }
        
        return sum;
    }
};