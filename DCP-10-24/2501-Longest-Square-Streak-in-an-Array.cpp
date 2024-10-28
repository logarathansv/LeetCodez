class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_map<int, int> mp;

        for(auto num:nums)
            mp[num] = 1;

        // 2 3 4 6 8 16
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i] >= 46341) break;
            if(nums[i] != nums[i+1] && mp.find(nums[i] * nums[i]) != mp.end()){
                mp[nums[i] * nums[i]] += mp[nums[i]];
            }
        }

        int ans = -1;
        for(auto mm : mp)
            ans = max(ans, mm.second);

        return ans == 1 ? -1 : ans;
    }
};