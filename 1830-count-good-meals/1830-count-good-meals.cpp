class Solution {
public:
    int countPairs(vector<int>& deliciousness) {
        unordered_map<int, int> mp;
        int ct = 0;
        long long MOD = 1000000007;
        
        for(auto num:deliciousness){
            for(int i=0;i<22;i++){
                ct = (ct + mp[(1<<i) - num])%MOD;
            }
            mp[num]++;
        }

        return ct;
    }
};