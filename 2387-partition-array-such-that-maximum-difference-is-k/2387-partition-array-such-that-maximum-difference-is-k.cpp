class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int ct = 1;
        int n = nums.size();

        sort(nums.begin(), nums.end());

        int s = nums[0], e = s;
        for(int i=0;i<n-1;i++){
            if(nums[i+1] - s > k) {
                s = nums[i+1];
                ct++;
            }
        }

        return ct;
    }
};