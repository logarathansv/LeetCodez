class Solution {
public:
    int strStr(string haystack, string needle) {
        vector<int> lps(needle.size());

        int prevlps = 0, i = 1;

        while(i < needle.size()){
            if(needle[i] == needle[prevlps]){
                lps[i] = prevlps + 1;
                prevlps += 1;
                i += 1;
            } else if(prevlps == 0){
                lps[i] = 0;
                i += 1;
            } else {
                prevlps = lps[prevlps - 1];
            }
        }
        
        int j =0; i = 0;

        while(i < haystack.size()){
            if(needle[j] == haystack[i]){
                j += 1; i += 1;}
            else {
                if(j == 0) i += 1;
                else {
                    j = lps[j-1];
                }
            }
            if(j == needle.size()) return i - needle.size();
        }

        return -1; 
    }
};