class Solution {
public:
    int findk(vector<int>& nums, int k){
        unordered_map<int, int> mp;
        int l = 0, len = 0;

        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;

            while(mp.size() > k && l < nums.size()){
                mp[nums[l]]--;
                if(mp[nums[l]] == 0) mp.erase(nums[l]);
                l++;
            }

            len += i-l+1;
        }

        return len;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return findk(nums, k) - findk(nums, k-1);
    }
};