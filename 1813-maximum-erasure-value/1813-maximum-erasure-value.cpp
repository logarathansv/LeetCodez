class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int sum = 0, maxi = INT_MIN, l = 0;
        unordered_map<int, int> mp;

        for(int r=0;r<nums.size();r++){
            while(mp.find(nums[r]) != mp.end()){
                sum -= nums[l];
                mp.erase(nums[l]);
                l++;
            }
            sum += nums[r];
            mp[nums[r]] = 1;
            
            maxi = max(sum, maxi);
        }

        return maxi;
    }
};