class Solution {
public:
    string removeStars(string s) {
        stack<char> st;
        string str = "";

        for(auto ch:s){
            if(ch == '*' && !st.empty()){
                st.pop();
            }
            else st.push(ch);
        }

        s = "";

        while(!st.empty()) {s += st.top(); st.pop();} 
        
        reverse(s.begin(), s.end());
        
        return s;
    }
};