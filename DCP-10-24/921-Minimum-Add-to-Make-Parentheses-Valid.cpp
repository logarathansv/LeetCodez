class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        for(char c:s){
            if(c == '('){
                st.push(c);
            }
            else if(!st.empty() && c == ')'){
                if(st.top() == '(')
                    st.pop();
                else st.push(c);
            }
            else st.push(c);
        }
        return st.size();
    }
};