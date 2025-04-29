class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxi = *max_element(nums.begin(), nums.end());
        int ct = 0, l = 0;
        long long ans = 0;
        int n = nums.size();

        for(int r = 0;r<n;r++){
            if(nums[r] == maxi) ct++;
            while(l < nums.size() && ct >= k){
                ans += (n - r);
                if(nums[l] == maxi) ct--;
                l++;
            }
        }

        return ans;
    }
};