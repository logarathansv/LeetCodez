class Solution {
public:
    int minimumLength(string s) {
        int alpha[26] = {0};
        int ans = 0;
        for(auto ch : s){
            alpha[ch-'a']++;
        }
        for(auto freq : alpha){
            if(freq != 0){
                if(freq % 2) ans += 1;
                else ans += 2;
            }
        }
        return ans;
    }
};