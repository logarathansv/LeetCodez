class Solution {
public:
    // Helper to check if two words differ by exactly one character
    bool differByOne(const string& a, const string& b) {
        int diff = 0;
        for (int i = 0; i < a.size(); ++i) {
            if (a[i] != b[i]) {
                ++diff;
                if (diff > 1) return false;
            }
        }
        return diff == 1;
    }

    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();
        vector<int> dp(n, 1);              
        vector<int> prev(n, -1);           
        int maxLen = 1, endIdx = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (groups[i] != groups[j] &&
                    words[i].length() == words[j].length() &&
                    differByOne(words[i], words[j])) {
                    if (dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        prev[i] = j;
                    }
                }
            }
            if (dp[i] > maxLen) {
                maxLen = dp[i];
                endIdx = i;
            }
        }

        vector<string> result;
        for (int i = endIdx; i != -1; i = prev[i]) {
            result.push_back(words[i]);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
