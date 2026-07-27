class Solution {
public:
    int numb(vector<int>& nums, int k){
        if(k< 0) return 0;

        int ct = 0, l = 0, ans = 0;

        for(int i=0;i<nums.size();i++){
            if(nums[i] % 2) ct++;

            while(ct > k && l < nums.size()){
                if(nums[l++] % 2) ct--;
            }

            ans += i-l+1;
        }

        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return numb(nums, k) - numb(nums,k -1);
    }
};