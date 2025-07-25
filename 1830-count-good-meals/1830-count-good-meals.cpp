class Solution {
public:
    int countPairs(vector<int>& deliciousness) {
        unordered_map<int, int> mp;
        int ct = 0;
        long long MOD = 1e9 + 7;
        vector<int> powers;
        
        for (int i = 0; i <= 21; ++i) {
            powers.push_back(1 << i);
        }

        for (int num : deliciousness) {
            for (int sum : powers) {
                int complement = sum - num;
                if (mp.count(complement)) {
                    ct = (ct + mp[complement]) % MOD;
                }
            }
            mp[num]++;
        }

        return ct;
    }
};
