class Solution {
public:
    string triangleType(vector<int>& nums) {
        int sum1 = nums[0] + nums[1];
        int sum2 = nums[1] + nums[2];
        int sum3 = nums[2] + nums[0];
        
        if(!(sum1 > nums[2] && sum2 > nums[0] && sum3 > nums[1])) return "none";

        if(nums[0] == nums[1] && nums[1] == nums[2]) return "equilateral";
        else if(nums[0] == nums[1] || nums[1] == nums[2] || nums[0] == nums[2]) return "isosceles";
        
        return "scalene";
    }
};