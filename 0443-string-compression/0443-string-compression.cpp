class Solution {
public:
    int compress(vector<char>& chars) {
        if (chars.size() == 1)
            return 1;
        int siz = 0;
        int ct = 1;
        char ch = chars[0];

        for (int i = 0; i < chars.size() - 1; i++) {
            if (chars[i] == chars[i + 1]) {
                ch = chars[i];
                ct++;
            } else {
                chars[siz++] = ch;
                string ctstr = to_string(ct);

                if (ct > 1)
                    for (auto ch : ctstr)
                        chars[siz++] = ch;
                        
                ct = 1;
                ch = chars[i + 1];
            }
        }
        if (ct >= 1) {
            chars[siz++] = ch;
            string ctstr = to_string(ct);

            if (ct > 1)
                for (auto ch : ctstr)
                    chars[siz++] = ch;
        }

        return siz;
    }
};