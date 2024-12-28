class Solution {
public:
    int findsubarr(vector<int> nums, int k){
        if(k<0) return 0;
        int l=0, r=0;
        int tot = 0, ct = 0;
        while(r<nums.size()){
            if(nums[r] % 2) ct++;
            while(ct>k){
                if(nums[l] % 2) ct--;
                l++;
            }
            tot += (r-l+1); 
            r++;
        }
        return tot;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return findsubarr(nums, k) - findsubarr(nums, k-1);
    }
};