class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size() < t.size()) return "";
        else if(s == t) return s;
        int len =-1, minlen = INT_MAX, l = 0, ct = 0, st = 0;

        unordered_map<char, int> mp;
        for(auto i:t) mp[i]++;

        for(int i=0;i<s.size();i++){
            if(mp[s[i]] > 0) ct++;
            mp[s[i]]--;
            while(ct == t.size()){
                len = i-l+1;
                if(len < minlen){
                    st = l;
                    minlen = len;
                }
                mp[s[l]]++;
                if(mp[s[l]] > 0) ct--;
                l++;
            }
        }

        return len == -1 ? "" : s.substr(st, minlen);
    }
};