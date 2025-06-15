class Solution {
public:
    int maxDiff(int num) {
        string s = to_string(num);
        string s2 = s;

        char ch;
        if(s[0] != '9') ch = s[0];
        else{
            int j=0;
            while(j < s.size() && s[j] == '9') j++;
            if(j<s.size()) ch = s[j];
        }

        for(auto& c:s) if(c == ch) c = '9';

        if(s2[0] != '1'){
            char ch2 = s2[0];
            for(auto& c:s2) if(c == ch2) c = '1';
        }
        else{
            char ch3 = 0;
            for(int i=1;i<s2.size();i++){
                if(s2[i] != '0' && s2[i] != '1'){
                    ch3 = s2[i];break;
                }
            }
            if(ch3){
                for(auto &c : s2) if(c == ch3) c = '0';
            }
        }

        return stoi(s) - stoi(s2);
    }
};