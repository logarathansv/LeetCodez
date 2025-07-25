class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum = accumulate(nums.begin(), nums.begin()+k, 0);
        double maxi = sum;

        for(int r=k;r<nums.size();r++){
            sum += nums[r] - nums[r-k];

            maxi = max(sum, maxi);
        }

        return maxi/k;
    }
};