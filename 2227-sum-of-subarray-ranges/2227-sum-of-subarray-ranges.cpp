class Solution {
public:
    void findExtremes(vector<int>& nse, vector<int>& pse, vector<int>& nge, vector<int>& pge, vector<int>& nums) {
        stack<int> st1, st2, st3, st4;
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            while (!st1.empty() && nums[st1.top()] >= nums[i]) st1.pop();
            pse[i] = (st1.empty()) ? -1 : st1.top();
            st1.push(i);

            while (!st2.empty() && nums[st2.top()] <= nums[i]) st2.pop();
            pge[i] = (st2.empty()) ? -1 : st2.top();
            st2.push(i);
        }

        for (int i = n - 1; i >= 0; i--) {
            while (!st3.empty() && nums[st3.top()] > nums[i]) st3.pop();
            nse[i] = (st3.empty()) ? n : st3.top();
            st3.push(i);

            while (!st4.empty() && nums[st4.top()] < nums[i]) st4.pop();
            nge[i] = (st4.empty()) ? n : st4.top();
            st4.push(i);
        }
    }

    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        long long mini = 0, maxi = 0;
        vector<int> nge(n), nse(n), pge(n), pse(n);

        findExtremes(nse, pse, nge, pge, nums);

        for (int i = 0; i < n; i++) {
            long long leftSmall = i - pse[i], rightSmall = nse[i] - i;
            long long leftLarge = i - pge[i], rightLarge = nge[i] - i;

            mini += leftSmall * rightSmall * nums[i];
            maxi += leftLarge * rightLarge * nums[i];
        }

        return maxi - mini;
    }
};
