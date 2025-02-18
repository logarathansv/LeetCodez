class Solution {
public:
    bool rotateString(string s, string goal) {
        if(goal.size() != s.size()) return false;
        int l = 0, f = 0;
        for(int i=0;i<s.length();i++){
            for(int j=0;j<goal.length();j++){
                if(s[(l+j)%s.length()] == goal[j]) f = 1;
                else {f=0;break;}
            }
            if(f) return true;
            l++;
        }
        return false;
    }
};