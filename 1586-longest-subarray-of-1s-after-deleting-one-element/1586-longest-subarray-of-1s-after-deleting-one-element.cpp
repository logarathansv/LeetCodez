class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int zeros = 0;
        int l = 0, maxi = INT_MIN;

        for(int r = 0;r<nums.size();r++){
            while(zeros > 1 && l < nums.size()) {
                if(nums[l++] == 0) zeros--;
            }
            if(nums[r] == 0) zeros++;

            maxi = max(maxi, r-l+1-zeros);
        }

        return maxi == nums.size() ? maxi-1 : maxi;
    }
};