class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int evct = 0, odct = 0, ect = 0, oct = 0;
        for(int i:nums) if(i%2 == 1) odct++; else evct++;

        if(nums[0] % 2 == 1){
            int f = 0;oct++;
            for(int i=1;i<nums.size();i++){
                if(nums[i] % 2 == f) oct++;
                else continue;
                f = !f;
            }
        }
        else if(nums[0] % 2 == 0){
            int f = 1;ect++;
            for(int i=1;i<nums.size();i++){
                if(nums[i] % 2 == f) ect++;
                else continue;
                f = !f;
            }
        }

        return max(max(evct, odct), max(oct, ect));
    }
};