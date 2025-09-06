class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int ct = 0;
        string str = "";

        for(int i=0;i<s.size();i++){
            
            if(s[i] == '(') ct++;
            else if(s[i] == ')') ct--;

            if(ct >= 0) str += s[i];
            if(ct < 0) ct = 0;
        }

        ct = 0;
        string nw = "";

        for(int i=str.size()-1;i>=0;i--){
            
            if(str[i] == ')') ct++;
            else if(str[i] == '(') ct--;

            if(ct >= 0) nw += str[i];
            if(ct < 0) ct = 0;
        }

        return string(nw.rbegin(), nw.rend());
    }
};