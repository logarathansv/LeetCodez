class Solution {
public:
    string decodeString(string s) {
        stack<string> st;
        stack<int> cst;
        string curr;
        int ct = 0;

        for(int i=0;i<s.size();i++){
            if(s[i] >= '0' && s[i] <= '9'){
                ct = ct * 10 + (s[i] - '0'); 
            }
            else if(s[i] == '['){
                cst.push(ct);
                st.push(curr);
                curr = "";ct = 0;
            }
            else if(s[i] == ']'){
                string tpstr = st.top();st.pop();
                int tpct = cst.top();cst.pop();

                for(int i=0;i<tpct;i++){
                    tpstr += curr;
                }

                curr = tpstr;
            }
            else curr += s[i];
        }

        return curr;
    }
};