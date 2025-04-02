class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long maxi = 0;
        long long sum = 0;
        for(int i=0;i<nums.size();i++){
            sum = nums[i];
            for(int j=i+1;j<nums.size();j++){
                sum -= nums[j];
                for(int k=j+1;k<nums.size();k++){
                    sum *= nums[k];
                    maxi = max(sum, maxi);
                    sum /= nums[k];
                }
                sum += nums[j];
            }
        }
        return maxi;
    }
};