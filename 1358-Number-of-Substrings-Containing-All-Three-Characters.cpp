class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char, int> freq;
        int res = 0;
        int act = 0, bct = 0, cct = 0;
        int i=0;

        for(int j=0;j<s.length();j++){
            freq[s[j]]++;
            while(freq['a'] > 0 && freq['b'] > 0 && freq['c'] > 0){
                res += (s.length()-j);
                freq[s[i]]--;
                i++;
            }
        }
        return res;
    }
};