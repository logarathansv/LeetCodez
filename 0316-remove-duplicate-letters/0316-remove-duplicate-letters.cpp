class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char, int> mp; for(int i=0;i<s.size();i++){ mp[s[i]] = i; } unordered_map<char, bool> seen; stack<char> st; for(int i=0;i<s.size();i++){ if(seen[s[i]] == true) continue; while(!st.empty() && st.top() > s[i] && mp[st.top()] > i){ seen[st.top()] = false; st.pop(); } st.push(s[i]); seen[s[i]] = true; } string ans; while(!st.empty()) { ans += st.top(); st.pop(); } reverse(ans.begin(), ans.end());return ans;
    }
};