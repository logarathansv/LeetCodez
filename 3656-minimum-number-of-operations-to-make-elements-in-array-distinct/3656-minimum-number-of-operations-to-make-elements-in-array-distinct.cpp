class Solution {
public:
    bool isDup(unordered_map<int, int>& mp){
        for(auto m:mp){
            if(m.second > 1) return false;
        }
        return true;
    }
    int minimumOperations(vector<int>& nums) {
        unordered_map<int, int> mp;
        int ct = 0;
        for(int num:nums) { mp[num]++; }
        for(int i=0;i<nums.size();i++) {
            if(isDup(mp)) break;
            int tp = i;
            for(int j=tp;j<min((int)tp+3, (int)nums.size());j++){
                mp[nums[j]]--;
            }
            i += 2;
            cout<<i<<" ";
            ct++;
        }
        return ct;
    }
};