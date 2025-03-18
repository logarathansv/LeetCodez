class Solution {
public:
// xr = 7;   // 111 (binary)
// nums[l] = 2; // 010 (binary)

// xr ^= nums[l]; 
// // 111 ^ 010 = 101 (binary) → xr = 5

// xr = 5;   // 101 (binary)
// nums[r] = 2; // 010 (binary)

// xr |= nums[r]; 
// // 101 | 010 = 111 (binary) → xr = 7
    int longestNiceSubarray(vector<int>& nums) {
        int mlen = 1;
        int l = 0;
        int xr = 0;
        for(int r=0;r<nums.size();r++){
            while((xr & nums[r]) != 0){
                xr ^= nums[l];
                l++;
            }
            xr |= nums[r];
            mlen = max(mlen, r-l+1);
        }
        return mlen;
    }
};