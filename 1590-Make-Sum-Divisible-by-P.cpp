class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long total = 0;
        for(auto it:nums)
            total += it;
        if(total % p == 0) return 0;
        int rem = total%p;
        long long prefixSum = 0;
        unordered_map<int,int> prefix;
        prefix[0] = -1;
        int minlen = nums.size();
        for(int i=0;i<nums.size();i++){
            prefixSum += nums[i];
            int currmod = prefixSum % p;
            int tarmod = (currmod-rem+p)%p;
            if(prefix.find(tarmod) != prefix.end()){
                minlen = min(minlen, i-prefix[tarmod]);
            }
            prefix[currmod] = i;
        }
        return minlen==nums.size() ? -1 : minlen;
    }
};