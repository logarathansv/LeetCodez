class Solution {
public:
    string compressedString(string word) {
        int ct = 1;
        string ans = "";
        for(int i=0;i<word.size();i++){
            if(ct > 8 && word[i] == word[i+1]){
                ans += (ct+'0');
                ans += word[i];
                ct = 0;
            }
            if(word[i] != word[i+1]){
                ans += (ct+'0');
                ans += word[i];
                ct = 1;
            }
            else ct++;
        }
        return ans;
    }
};