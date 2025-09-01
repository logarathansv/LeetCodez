class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans;
        string str;
        int ct = 0;

        for(int i=0;i<s.size();i++){
            char ch = s[i];
            
            if(ch == '(') ct++;
            else ct--;

            if(ct > 0) {
                ans += ch;
            }
        }

        return ans;
    }
};