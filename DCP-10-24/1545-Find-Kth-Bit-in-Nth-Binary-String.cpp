class Solution {
public:
    char findKthBit(int n, int k) {
        if(k == 1) return '0';
        string sn = "011";
        int ch = 1;
        for(int i=0;i<n-2;i++){
            string ans = sn+"1";
            sn[ch] = sn[ch] == '1' ? '0' : '1';
            ans += sn;
            sn = ans;
            ch = ch*2+1;
        }
        return sn[k-1];
    }
};