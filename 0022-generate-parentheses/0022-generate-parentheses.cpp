class Solution {
public:
    void generate(int op, int cl, vector<string>& ans, string s, int n){
        if(s.length() == n){
            ans.push_back(s);
        }
        if(op < n/2) generate(op+1, cl, ans, s+'(', n);
        if(cl < op) generate(op, cl+1, ans, s+')', n);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        int open = 0, close = 0;

        generate(open, close, ans, "", 2*n);
        return ans;
    }
};