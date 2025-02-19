class Solution {
public:
    bool validateparenthesis(string s){
        stack<char> st;
        for(auto ch:s){
            if(ch == '(') st.push(ch);
            else if(!st.empty())
                if(ch == ')' && st.top() == '(')
                    st.pop();
                else return false;
            else return false;
        }
        return true;
    }
    void generate(vector<string>& ans, string s, int n, unordered_map<char, int>& freq){
        if(s.length() == n){
            if(s[0] != '(' && s[n-1] != ')') return;
            else if(validateparenthesis(s)) ans.push_back(s);
            return ;
        }
        for(auto& [brac, fre] : freq){
            if(fre > 0){
                freq[brac]--;
                generate(ans, s+brac, n, freq);
                freq[brac]++;
            }
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        unordered_map<char, int> freq;
        freq['('] = n;
        freq[')'] = n;

        generate(ans, \\, 2*n, freq);
        return ans;
    }
};