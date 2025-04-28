class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long ans = 0;
        long long sum = 0;
        int len = 0;
        int l = 0;

        for(int i=0;i<nums.size();i++){
            len++;
            sum += nums[i];
            while(l < nums.size() && sum*len >= k){
                sum -= nums[l++];
                len--;
            }
            ans += (i-l+1);
        }

        return ans;
    }
};