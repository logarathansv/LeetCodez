class Solution {
public:
    int strStr(string haystack, string needle) {
        if(haystack == needle) return 0;
        if(haystack.size() < needle.size()) return -1;

        int size = needle.size();
        for(int i=0;i<haystack.size()-size+1;i++){
            if(haystack.substr(i, size) == needle){
                return i;
            }
        }

        return -1;
    }
};