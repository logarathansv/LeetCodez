class Solution {
public:
    string smallestNumber(string pattern) {
        stack<int> st;
        string res = "";

        for(int ind = 0;ind <= pattern.size();ind++){
            st.push(ind + 1);

            if(ind == pattern.size() || pattern[ind] == 'I'){
                while(!st.empty()){
                    res += to_string(st.top())[0];
                    st.pop();
                }
            }
        }
        return res;
    }
};