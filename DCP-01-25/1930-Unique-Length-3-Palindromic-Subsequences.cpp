class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_set<char> done;
        unordered_set<string> st;
        char chosen;
        string res = "";
        unordered_map<char, bool> check;
        for(int i=0;i<s.length();i++){
            chosen = s[i];
            if(!check[chosen]){
                for(int j=s.length()-1;j>i+1;j--){
                    if(chosen == s[j]){
                        for(int start = i+1;start<j;start++){
                            res += s[i];
                            res += s[start];
                            res += s[j];
                            st.insert(res);
                            res = "";
                        }
                        break;
                    }
                }
            }
            check[chosen] = true;
        }
        return st.size();
    }
};