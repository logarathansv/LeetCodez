class Solution {
public:
    bool doesAliceWin(string s) {
        int even = 1;
        int odd = 0;
        int parity = 0;
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};

        for (char ch : s) {
            if (vowels.count(ch)) {
                parity ^= 1;
            }
            if (parity == 0) {
                even++;
            } else {
                odd++;
            }
        }

        return (long)even * odd > 0;
    }
};