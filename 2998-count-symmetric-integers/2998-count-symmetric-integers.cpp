class Solution {
public:
    bool isSymmetric(string s){
        int s1 = 0,s2 = 0;
        if(s.size() % 2) return false;
        for(int i=0;i<s.size()/2;i++) s1 += (s[i] - '0');
        for(int i=s.size()/2;i<s.size();i++) s2 += (s[i] - '0');
        return s1 == s2;
    }
    int countSymmetricIntegers(int low, int high) {
        int ct = 0;
        for(int i=low;i<high+1;i++){
            if(isSymmetric(to_string(i))) ct++;
        }
        return ct;
    }
};