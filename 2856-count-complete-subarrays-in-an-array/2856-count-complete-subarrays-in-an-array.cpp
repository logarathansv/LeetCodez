class Solution {
public:
    int count(vector<int>& nums, int k){
        if(k < 0) return 0;
        unordered_map<int, int> mp;

        int ct = 0, l = 0;
        for(int r=0;r<nums.size();r++){

            mp[nums[r]]++;
            
            while(mp.size() > k){
                mp[nums[l]]--;
                if(mp[nums[l]] == 0) mp.erase(nums[l]);
                l++;
            }
            
            ct += (r - l + 1);

        }
        cout<<ct;
        return ct;
    }   
    int countCompleteSubarrays(vector<int>& nums) {
        int k = 0;
        unordered_set<int> st;

        for(auto num:nums) st.insert(num);

        k = st.size();

        return count(nums, k) - count(nums, k-1);
    
        // unordered_set<int> st;
        // int st1 = 0, ans = 0;

        // for(auto num:nums) st.insert(num);

        // st1 = st.size();

        // for(int i=0;i<nums.size();i++){
        //     st.clear();
        //     for(int j=i;j<nums.size();j++){
        //         st.insert(nums[j]);
        //         if(st.size() == st1) ans++;
        //     }
        // }
        // return ans;
    }
};