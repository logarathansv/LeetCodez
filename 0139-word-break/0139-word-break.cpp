class Solution {
public:
    bool check(int ind, string& s, unordered_set<string>& st, vector<int>& memo){
        if(ind == s.size()) return true;

        if(memo[ind] != -1) return memo[ind];

        for(int i=ind;i<s.size();i++){
            string str = s.substr(ind, i-ind+1);
            cout<<ind<<" "<<str;
            if(st.find(str) != st.end()){
                if(check(i+1, s, st, memo)) return memo[ind] = true;
            }
            cout<<endl;
        }

        return memo[ind] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        vector<int> memo(s.size(), -1);

        return check(0, s, st, memo);
    }
};