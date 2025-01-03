class Solution {
public:
    int maxScore(string s) {
        int l = 0, r = 0, maxi = INT_MIN;
        for(char c : s) r = (c == '1') ? r+1 : r;
        for(int i = 0;i<s.length()-1;i++){
            if(s[i] == '0') l++ ;
            else r--;
            maxi = max(maxi, l+r);
        }
        return maxi;
    }
};