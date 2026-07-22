class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        sort(nums.rbegin(), nums.rend());
        vector<int> ans(nums.size());
        int k=1;
        int i;
        for( i=0;k<nums.size();i++){
            ans[k] = nums[i];
            k+=2;
        }
        k = 0;
        for(i;k<nums.size();i++){
            ans[k] = nums[i];
            k +=2;
        }

        nums = ans;
        return;
    }
};