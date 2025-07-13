class Solution {
public:
    int isVowel(char ch){
        string str = "aeiouAEIOU";
        return (str.find(ch) != string::npos);
    }
    string reverseVowels(string s) {
        vector<int> inds;

        for(int i=0;i<s.size();i++) if(isVowel(s[i])) inds.push_back(i);

        for(int i=0;i<inds.size()/2;i++){
            swap(s[inds[i]], s[inds[inds.size()-i-1]]);
        }

        return s;
    }
};