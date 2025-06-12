class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int maxi = INT_MIN;

        for(int i=0;i<nums.size()-1;i++){
            maxi = max(abs(nums[i]-nums[i+1]), maxi);
        }
        maxi = max(abs(nums[0] - nums[nums.size()-1]), maxi);

        return maxi;
    }
};