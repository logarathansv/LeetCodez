class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0, len = 0, maxi = INT_MIN;
        unordered_map<char, int> mp;

        for(int i=0;i<s.size();i++){
            mp[s[i]]++;

            maxi = max(maxi, mp[s[i]]);
            if((i-l+1 - maxi)>k){
                mp[s[l]]--;
                l++;
            }

            len = max(len, i-l+1);
        }

        return len;
    }
};