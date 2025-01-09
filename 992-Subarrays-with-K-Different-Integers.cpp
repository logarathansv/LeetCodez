class Solution {
public:
    int findarr(vector<int> nums, int k){
        if(k<0) return 0;
        int l = 0;
        unordered_map<int, int> mp;
        int ct = 0;
        for(int r=0;r<nums.size();r++){
            mp[nums[r]]++;
            while(mp.size()>k){
                mp[nums[l]]--;
                if(mp[nums[l]] == 0){
                    mp.erase(nums[l]);
                }
                l++;
            }
            ct += (r-l+1);
        }
        cout<<ct;
        return ct;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return findarr(nums, k) - findarr(nums, k-1);
    }
};