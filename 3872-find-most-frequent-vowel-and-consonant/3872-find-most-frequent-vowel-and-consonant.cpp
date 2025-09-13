class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map<char, int> mp;
        int maxi = 0, maxi2 = 0;

        for(char ch:s){
            mp[ch]++;
            if(string("aeiou").find(ch) != string::npos){
                maxi = max(maxi, mp[ch]);
            } else {
                maxi2 = max(maxi2, mp[ch]);
            }
        }

        return maxi + maxi2;
    }
};