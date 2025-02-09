class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long bad = 0;
        unordered_map<int, int> mp;
        // map will say like whether the diff is already present..
        // also says how many
        for(int i=0;i<nums.size();i++){
            int good = mp[i-nums[i]];
            // good is the number of non bad pairs equal check
            // at first no bad pairs
            bad += (i-good);
            mp[i-nums[i]] = good + 1;
            // on having the first difference storing the diff in map
        }
        return bad;
    }
};