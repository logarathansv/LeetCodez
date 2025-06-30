class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> mp;
        int maxi = 0;
        
        for(auto num : nums) mp[num]++;

        for(auto [ele, ct] : mp){
            if(mp.find(ele + 1) != mp.end()){
                int curr = ct + mp[ele+1];

                maxi = max(maxi, curr);
            }
        }

        return maxi;
    }
};