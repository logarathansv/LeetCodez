class Solution {
public:
    int minChanges(string s) {
        int ct1 = 1;
        int ans = 0;
        for(int i=0;i<s.length();i++){
            if(s[i] != s[i+1]){
                if(ct1 % 2){
                    ans++;
                    i++;
                }
                ct1 = 1;
            }
            else ct1++;
            
        }
        return ans;
    }
};