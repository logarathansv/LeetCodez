class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> mp;
        unordered_map<char, int> mp2;
        for(auto ch:s1) mp[ch]++;

        int l = 0;

        for(int r=0;r<s2.size();r++){
            mp2[s2[r]]++;

            if(s1.size() < r-l+1) {
                mp2[s2[l]]--;

                if(mp2[s2[l]] == 0) mp2.erase(s2[l]);
                l++;
            }

            if(mp == mp2) return true;            
        }

        return false;
    }
};