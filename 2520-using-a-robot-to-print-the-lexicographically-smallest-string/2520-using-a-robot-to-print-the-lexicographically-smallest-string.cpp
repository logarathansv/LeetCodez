class Solution {
public:
    string robotWithString(string s) {
        int n = s.size();
        string ans;
        stack<char> st;

        vector<char> minSuffix(n);
        minSuffix[n - 1] = s[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            minSuffix[i] = min(s[i], minSuffix[i + 1]);
        }

        for (int i = 0; i < n; ++i) {
            st.push(s[i]);

            while (!st.empty() && st.top() <= minSuffix[i + 1 < n ? i + 1 : i]) {
                ans += st.top();
                st.pop();
            }
        }

        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        return ans;
    }
};
