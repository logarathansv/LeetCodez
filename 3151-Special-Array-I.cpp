class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        if(nums.size() == 1) return true;
        bool isOdd = false;
        if(nums[0] % 2) isOdd = true;
        for(int i=1;i<nums.size();i++){
            if(isOdd){
                if(nums[i] % 2 == 0) {isOdd = !isOdd;continue;}
                else return false;
            }
            else{
                if(nums[i] % 2) {isOdd = !isOdd;continue;}
                else return false;
            }
        }
        return true;
    }
};