class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int ans = INT_MIN;
        
        vector<int> suf(nums.size());
        vector<int> pre(nums.size());

        suf[0] = nums[0];
        for(int i=1;i<nums.size();i++){
            suf[i] = min(nums[i], suf[i-1]);
        }
        
        pre[nums.size() - 1] = nums[nums.size() - 1];
        for(int i=nums.size()-2;i>=0;i--){
            pre[i] = max(nums[i], pre[i+1]);
        }

        for(int i=0;i<nums.size();i++){
            ans = max(pre[i] - suf[i], ans);
        }

        return (ans == 0) ? -1 : ans;
    }
};