class Solution {
public:
    bool oper(string& num) {
        if(num == "+" || num == "-" || num == "*" || num == "/")
            return true;
        return false;
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for(int i=0;i<tokens.size();i++){
            string num = tokens[i];

            if(!oper(num)) {st.push(stoi(num));}
            else{
                int n2 = st.top();st.pop();
                int n1 = st.top();st.pop();

                if(num == "+") st.push(n1+n2);
                if(num == "-") st.push(n1-n2);
                if(num == "/") st.push(n1/n2);
                if(num == "*") st.push(n1*n2);
            }
        }

        return st.top();
    }
};