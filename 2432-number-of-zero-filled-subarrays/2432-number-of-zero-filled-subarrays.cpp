class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int l = 0, n = nums.size();
        long long ct = 0;
        
        for(int r=0;r<n;r++){
            if(nums[r] == 0){
                l = r;
                while(r < n && nums[r] == 0){
                    ct += (r - l + 1);
                    r++;
                }   
            }
        }

        return ct;
    }   
};