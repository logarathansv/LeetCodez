class Solution {
public:
    int longestBeautifulSubstring(string word) {
        int len = 1, maxlen = 0;
        int ct = 1;
        for(int r = 1;r < word.length();r++){
            if(word[r-1] == word[r]) len++;
            else if(word[r-1] < word[r]) {
                len++;
                ct++;
            }
            else {
                len = 1;
                ct = 1;
            }
            if(ct == 5){
                maxlen = max(len, maxlen);
            }
        }
        return maxlen;
    }
};