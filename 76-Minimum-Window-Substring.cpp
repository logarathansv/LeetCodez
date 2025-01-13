class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() < t.size())
            return \\;
        else if (s == t)
            return s;
        unordered_map<int, int> mp;
        int minlen = INT_MAX, start = 0, ct = 0, len = -1;
        int l = 0;
        for (auto ch : t)
            mp[ch]++;
        for (int r = 0; r < s.size(); r++) {
            if (mp[s[r]] > 0)
                ct++;
            mp[s[r]]--;
            while (ct == t.size()) {
                len = r-l+1;
                if (len < minlen) {
                    start = l;
                    minlen = len;
                }
                mp[s[l]]++;
                if(mp[s[l]] > 0) ct--;
                l++;
            }
        }
        return len==-1 ? \\ : s.substr(start, minlen);
    }
};