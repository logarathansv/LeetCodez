class Solution {
public:
    bool canConstruct(string s, int k) {
        if(s.length() < k) return false;
        int mp[26] = {0};
        int ct = 0;
        for(auto ch: s){
            mp[ch - 'a']++;
        }
        for(auto ch: mp){
            if(ch % 2) ct++;
        }
        if(ct>k) return false;
        return true;
    }
};