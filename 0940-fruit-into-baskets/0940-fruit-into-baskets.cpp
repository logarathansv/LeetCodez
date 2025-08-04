class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_set<int> st;
        unordered_map<int, int> mp;
        int l = 0, r = 0;
        int maxlen = 0, len = 0;
        for (r = 0; r < fruits.size(); r++) {
            st.insert(fruits[r]);
            mp[fruits[r]]++;
            // for(auto it:st) cout<<it;
            while (st.size() > 2) {
                mp[fruits[l]]--;
                if (mp[fruits[l]] == 0) {
                    mp.erase(fruits[l]);
                    st.erase(fruits[l]);
                }
                l++;
            }
            // cout<<'\n'<<r-l+1<<'\n';
            maxlen = max(maxlen, r - l + 1);
        }
        return maxlen;
    }
};