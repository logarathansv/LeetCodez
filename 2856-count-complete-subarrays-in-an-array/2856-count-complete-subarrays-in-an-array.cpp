class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_set<int> st;
        int st1 = 0, ans = 0;

        for(auto num:nums) st.insert(num);

        st1 = st.size();

        for(int i=0;i<nums.size();i++){
            st.clear();
            for(int j=i;j<nums.size();j++){
                st.insert(nums[j]);
                if(st.size() == st1) ans++;
            }
        }
        return ans;
    }
};