class Solution {
public:
    string robotWithString(string s) {
        string ans;

        stack<char> st;
        unordered_map<char, int> ct;

        for(auto ch:s) ct[ch]++;
        char minc = 'a';

        for(int i=0;i<s.size();i++){
            ct[s[i]]--;
            st.push(s[i]);

            while(minc != 'z' && ct[minc] == 0) minc++;

            while(!st.empty() && st.top() <= minc){
                ans += st.top();
                st.pop();
            }
        }

        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }

        return ans;
    }
};