class Solution {
public:
    bool isSubsequence(string s, string t) {
        int si = 0;

        for(auto ch:t) if(ch == s[si]) si++;

        if(si == s.size()) return true;
        return false;
    }
};