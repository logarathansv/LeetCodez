class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size()) return false;

        for(int i=0;i<goal.size();i++){
            string s1 = goal.substr(0, i);
            string s2 = goal.substr(i, s.size()-i);

            if((s2+s1) == s) return true;
        }

        return false;
    }
};