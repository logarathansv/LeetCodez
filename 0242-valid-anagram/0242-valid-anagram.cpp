class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> mp;
        unordered_map<char, int> mp2;

        for(auto ch:s) mp[ch]++;
        for(auto ch:t) mp2[ch]++;

        return mp == mp2;
    }
};