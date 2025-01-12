class Solution {
public:
    bool canBeValid(string s, string locked) {
        if (s.size() % 2 != 0) return false;

        int open = 0, close = 0, flexible = 0;
        for (int i = 0; i < s.size(); i++) {
            if (locked[i] == '0') flexible++;  
            else if (s[i] == '(') open++;      
            else close++;                      

            if (close > open + flexible) return false;
        }

        open = close = flexible = 0;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (locked[i] == '0') flexible++;  
            else if (s[i] == '(') open++;      
            else close++;                      

            if (open > close + flexible) return false;
        }

        return true;
    }
};
