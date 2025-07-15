class Solution {
public:
    int isvowel(char ch){
        string str = "aeiouAEIOU";
        return (str.find(ch) != string::npos);
    }
    bool isValid(string word) {
        bool isVP = false, isCP = false;

        if(word.size() < 3) return false; 

        for(auto ch:word){
            if(isdigit(ch) != 0) continue;
            else if(isalpha(ch) && !isvowel(ch)) isCP = true;
            else if(isvowel(ch)) isVP = true;
            else return false;
        } 

        return isVP && isCP;
    }
};