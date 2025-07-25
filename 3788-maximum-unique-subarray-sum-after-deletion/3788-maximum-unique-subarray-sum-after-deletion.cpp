class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_set<int> st;

        for(auto num : nums){
            if(num > 0) st.insert(num);
        }

        if(st.size() == 0) return *max_element(nums.begin(), nums.end());
        int sum = 0;
        sum = accumulate(st.begin(), st.end(), 0);

        return sum;
    }
};