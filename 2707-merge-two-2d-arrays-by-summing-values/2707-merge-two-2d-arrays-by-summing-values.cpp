class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        vector<vector<int>> ans;
        map<int, int> mp;
        for(auto num:nums1) mp[num[0]] = num[1];
        for(auto num:nums2) {
            if(mp.find(num[0]) == mp.end())
                mp[num[0]] = num[1];
            else{
                mp[num[0]] = mp[num[0]] + num[1];
            }
        }
        for(auto num:mp){
            ans.push_back({num.first, num.second});
        }
        return ans;
    }
};