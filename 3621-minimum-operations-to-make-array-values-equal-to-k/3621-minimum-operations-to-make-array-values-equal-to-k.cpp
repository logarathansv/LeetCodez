class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int ct = 0;
        for(int num:nums) if(num < k) return -1;
        unordered_map<int, int> mp;
        for(int num:nums) {
            mp[num]++;
        } 
        for(auto num:mp) {
            if(num.first > k) ct++;
        }
        return ct;
    }
};