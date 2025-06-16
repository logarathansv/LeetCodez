class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int ans = INT_MIN;

        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if(nums[j] > nums[i]) ans = max(nums[j] - nums[i], ans);
            }
        }

        return (ans == INT_MIN) ? -1 : ans;
    }
};