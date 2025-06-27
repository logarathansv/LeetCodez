class Solution {
public:
    bool isValid(string& s, string& pattern, int k) {
        int cnt = 0, j = 0;
        for (char c : s) {
            if (c == pattern[j]) j++;
            if (j == pattern.size()) {
                cnt++;
                if (cnt >= k) return true;
                j = 0;
            }
        }
        return false;
    }

    void dfs(string& s, string current, string& best, vector<char>& chars, int k) {
        if (current.size() > 7) return;
        if (isValid(s, current, k)) {
            if (current.size() > best.size() || (current.size() == best.size() && current > best)) {
                best = current;
            }
            for (char c : chars) {
                dfs(s, current + c, best, chars, k);
            }
        }
    }

    string longestSubsequenceRepeatedK(string s, int k) {
        unordered_map<char, int> freq;
        for (char c : s) freq[c]++;
        vector<char> chars;
        for (auto& [c, f] : freq) {
            if (f >= k) chars.push_back(c);
        }

        string best = "";
        dfs(s, "", best, chars, k);
        return best;
    }
};
