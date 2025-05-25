class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int num = 0, f = 0;

        unordered_map<string, int> st;
        for (string word : words)
            st[word]++;

        for (auto& word:st) {
            string wd = "";
            wd += word.first[1];
            wd += word.first[0];
            if (wd != word.first) {
                if (st.find(wd) != st.end()) {
                    cout << wd << "FOund " << '\n';
                    int pairs = min(st[wd], st[word.first]);
                    num += pairs * 4;
                    st[wd] -= pairs;
                    st[word.first] -= pairs;
                }
            }
            else{
                num += (word.second / 2) * 4;
                if(word.second % 2 == 1) f = 1;
            }
        }
        if (f == 1)
            num += 2;

        return num;
    }
};