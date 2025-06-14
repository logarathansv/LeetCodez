class Solution {
public:
    int minMaxDifference(int num) {
        string s = to_string(num);
        string s1 = s;
        string s2 = s;

        int i=0;
        while(i<s.size() && s[i] == '9') i++; 

        if(i < s.size()) {    
            char torep = s[i];
            for(int i=0;i<s1.size();i++){
                if(s1[i] == torep) s1[i] = '9';
            }
        }

        char first = s2[0];
        for(int i=0;i<s2.size();i++){
            if(s2[i] == first) s2[i] = '0';
        }

        return stoi(s1) - stoi(s2);
    }
};