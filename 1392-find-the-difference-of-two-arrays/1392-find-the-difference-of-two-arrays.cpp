class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> ans(2);

        unordered_set<int> st;

        for(auto num:nums2) st.insert(num);
        for(auto num:nums1) {
            if(st.find(num) == st.end()) {ans[0].push_back(num);st.insert(num);}
        }
        st.clear();
        for(auto num:nums1) st.insert(num);
        for(auto num:nums2) {
            if(st.find(num) == st.end()) {ans[1].push_back(num);st.insert(num);}
        }

        return ans;
    }
};