class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<int, int> mp;
        int l =0 ;
        int len = INT_MIN, maxi = INT_MIN;

        for(int r=0;r<s.size();r++){
            mp[s[r] - 'A']++;

            maxi = max(maxi, mp[s[r] - 'A']);

            if((r-l+1 - maxi) > k){
                mp[s[l] - 'A']--;
                l++;
            }

            len = max(r-l+1, len);
        }

        return len;
    }
};