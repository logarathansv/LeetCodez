class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int equal = 0;
        int sp1 = -1, sp2 = -1;
        for(int i=0;i<s1.size();i++){
            if(s1[i] != s2[i]) {
                equal++;
                if(sp1 == -1) sp1 = i;
                else if(sp2 == -1) sp2 = i; 
            }
        }
        if(equal == 0) return true;
        if(equal == 2 && s1[sp2] == s2[sp1] && s1[sp1] == s2[sp2]) return true;
        return false;
    }
};