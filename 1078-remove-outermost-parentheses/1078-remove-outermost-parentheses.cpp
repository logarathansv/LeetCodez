class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans;
        string str;
        int ct = 0;

        for(int i=0;i<s.size();i++){
            char ch = s[i];
            str += ch;
            
            if(ch == '(') ct++;
            else ct--;

            if(ct == 0) {
                ans += str.substr(1, str.size()-2);
                str = "";
            }
        }

        return ans;
    }
};