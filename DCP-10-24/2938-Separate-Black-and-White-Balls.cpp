class Solution {
public:
    long long minimumSteps(string s) {
        long long step = 0;
        int count = 0;
        for(int i=0;i<s.length();i++){
            if(s[i] == '0'){
                step += (i-count);
                count++;
            }
        }
        return step;
    }
};