class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int prev = nums[0], ct = 0;

        for(int i=1;i<nums.size()-1;i++){
            if(nums[i] == nums[i+1]) continue;

            if(prev > nums[i] && nums[i] < nums[i+1]) ct++;  
            else if(prev < nums[i] && nums[i] > nums[i+1]) ct++; 

            prev = nums[i];      
        }

        return ct;
    }
};