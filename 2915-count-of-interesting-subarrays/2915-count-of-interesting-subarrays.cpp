class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1;
        long long ans = 0;
        int prf = 0;
        for(int i=0;i<nums.size();i++){
            prf += (nums[i] % modulo == k);
            ans += mp[(prf - k + modulo) % modulo];
            mp[prf % modulo]++;
        }
        return ans;
    }
};