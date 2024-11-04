class Solution {
public:
    string makeFancyString(string s) {
        string ans = "";
        int ct = 1;
        for(int i=0;i<s.length();i++){
            if(s[i] == s[i+1]){
                ct++;
            }
            else ct = 1;
            if(!(ct > 2)) {
                ans += s[i];
            }
        }
        return ans;
    }
};