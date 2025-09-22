class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> mp;
        int maxi = INT_MIN;
        
        for(auto num:nums){ mp[num]++;maxi = max(maxi, mp[num]);}

        int ct = 0;

        for(auto ele:mp) {
            
            if(ele.second == maxi) ct += ele.second;
                    }

        return ct;
    }
};