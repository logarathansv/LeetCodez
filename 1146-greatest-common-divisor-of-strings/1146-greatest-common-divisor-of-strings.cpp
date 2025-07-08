class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int minLen = min(str1.size(), str2.size());

        for (int i = minLen; i >= 1; --i) {
            string candidate = str1.substr(0, i);

            if (str1.size() % i != 0 || str2.size() % i != 0) continue;

            if (isDivisible(str1, candidate) && isDivisible(str2, candidate)) {
                return candidate;
            }
        }

        return "";
    }

private:
    bool isDivisible(const string& str, const string& pattern) {
        int len = pattern.size();
        for (int i = 0; i < str.size(); i += len) {
            if (str.substr(i, len) != pattern) return false;
        }
        return true;
    }
};
