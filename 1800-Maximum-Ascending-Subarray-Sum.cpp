class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        int sum = nums[0];
        int msum = nums[0];
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i+1] <= nums[i]){
                sum = 0;
            }
            sum += nums[i+1];
            msum = max(sum, msum);
            
            cout<<msum<<" "<<sum;
        }
        return msum;
    }
};