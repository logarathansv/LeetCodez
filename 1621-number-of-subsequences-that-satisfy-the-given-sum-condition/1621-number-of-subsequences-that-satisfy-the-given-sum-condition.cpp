class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int mod = 1e9 + 7;
        int n = nums.size();
        vector<int> pow2(n, 1);

        for (int i = 1; i < n; i++)
            pow2[i] = (pow2[i - 1] * 2) % mod;

        sort(nums.begin(), nums.end());
        int left = 0, right = n - 1;
        int result = 0;

        while (left <= right) {
            if (nums[left] + nums[right] <= target) {
                result = (result + pow2[right - left]) % mod;
                left++;
            } else {
                right--;
            }
        }

        return result;
    }
};
