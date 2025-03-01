class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i] == nums[i+1]){
                nums[i] *= 2;
                nums[i+1] = 0; 
            }
        }
        int i=0;
        for(int j=0;j<nums.size();j++){
            if(nums[j] == 0){
                i = j;
                while(i < nums.size() && nums[i] == 0) i++;
                if(i<nums.size()) swap(nums[i], nums[j]);
            }            
        }
        return nums;
    }
};