class Solution {
public:
    int kadane(int num, vector<int>& nums, int k){
        int cur = 0, mx = 0;
        for(int n : nums){
            if(n == num) cur++;
            if(k == n) cur--;
            if(cur < 0) cur = 0;

            mx = max(mx, cur);
        }
        return mx;
    }
    int maxFrequency(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int mx = 0;

        for(auto num:nums) mp[num]++;

        for(auto num:mp) mx = max(mx, kadane(num.first, nums, k));

        return count(nums.begin(), nums.end(), k) + mx;
    }
};