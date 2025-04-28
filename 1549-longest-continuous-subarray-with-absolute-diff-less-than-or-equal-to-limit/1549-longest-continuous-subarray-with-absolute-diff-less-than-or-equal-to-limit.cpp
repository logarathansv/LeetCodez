class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int l = 0, len = 0;
        multiset<int> mst;

        for(int r=0;r<nums.size();r++){
            mst.insert(nums[r]);

            while(*mst.rbegin() - *mst.begin() > limit){                
                mst.erase(mst.find(nums[l]));
                l++;
            }

            len = max(r - l + 1, len);
        }

        return len;
    }
};