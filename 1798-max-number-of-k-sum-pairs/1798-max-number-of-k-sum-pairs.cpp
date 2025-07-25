class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int ct = 0;

        for(auto num : nums){
            if(mp.find(k - num) != mp.end()){
                ct++;
                int tar = k-num;
                mp[tar]--;
                if(mp[tar] == 0) mp.erase(tar);
            } 
            else mp[num] ++;
        }

        return ct;
    }
};