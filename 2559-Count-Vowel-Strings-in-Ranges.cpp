class Solution {
public:
    bool isVowel(char c){
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            return true;
        return false;
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        int sum = 0;
        vector<int> res(queries.size());
        vector<int> table(n, 0);
        for(int i = 0;i<words.size();i++){
            if(isVowel(words[i][0]) && isVowel(words[i][words[i].size()-1]))
                sum++;
            table[i] = sum;
        }
        for(int i=0;i<res.size();i++){
            res[i] = table[queries[i][1]] - (queries[i][0] != 0 ? table[queries[i][0]-1] : 0);
        }
        return res;
    }
};