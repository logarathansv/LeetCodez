class Solution {
public:
    vector<string> ans;
    void combi(int ind, string str, unordered_map<char, string>& mp, string digits){
        if(str.size() == digits.size()) {ans.push_back(str); return;}

        for(auto ch:mp[digits[ind]]){
            combi(ind + 1, str + ch, mp, digits);
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits == "") return {};
        unordered_map<char, string> mp;
        string combo[] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        for(int i=2;i<=9;i++){
            mp[i + '0'] = combo[i-2];
        }

        combi(0, "", mp, digits);

        return ans;
    }
};