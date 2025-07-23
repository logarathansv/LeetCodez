class Solution {
public:
    int removePair(string& str, string pr, int num){
        stack<char> st;
        int ans = 0;

        for(int i=0;i<str.size();i++){
            if(!st.empty() && pr[0] == st.top() && pr[1] == str[i]){
                ans += num;
                st.pop();
            }
            else st.push(str[i]);
        }

        str = "";
        while(!st.empty()) {str.push_back(st.top()); st.pop();}

        return ans;
    }
    int maximumGain(string s, int x, int y) {
        string chose = x>y ? "ab" : "ba";
        int res = 0;

        res += removePair(s, chose, max(x, y));
        res += removePair(s, chose, min(x, y));

        return res;
    }
};