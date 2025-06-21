class Solution {
public:
    int minimumDeletions(string word, int k) {
        int ans = INT_MAX;

        unordered_map<char, int> mp;

        for(auto ch:word) mp[ch]++;

        for (auto &[_, a] : mp) {
            int deleted = 0;
            for (auto &[_, b] : mp) {
                if (a > b) {
                    deleted += b;
                } else if (b > a + k) {
                    deleted += b - (a + k);
                }
            }
            ans = min(ans, deleted);
        }

        return ans;
    }
};