class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> mp;
        int ans = -1;

        for(auto num:arr) mp[num]++;

        for(auto num:mp) if(num.first == num.second) ans = max(num.first, ans);

        return ans;
    }
};