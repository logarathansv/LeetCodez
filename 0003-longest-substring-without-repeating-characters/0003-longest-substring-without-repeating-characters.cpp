class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> mp(256, 0);

        int len = 0, l = 0;
        for(int i=0;i<s.size();i++){
            while(mp[s[i]] != 0){
                mp[s[l]] = 0;
                l++;
            }
            mp[s[i]] = 1;
            len = max(len, i-l+1);
        }

        return len;
    }
};