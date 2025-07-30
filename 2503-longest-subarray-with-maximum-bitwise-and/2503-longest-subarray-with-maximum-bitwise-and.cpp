class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int mx = 0, ans = 0, ct = 0;

        for(auto num:nums){
            if(mx < num){
                mx = num;
                ans = ct = 0;
            }
            if(mx == num) ct++;
            else ct = 0;
            ans = max(ans, ct);
        }

        return ans;
    }
};