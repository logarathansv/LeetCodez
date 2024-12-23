class Solution {
public:
    int characterReplacement(string s, int k) {
        int i,j;
        i=0,j=0;
        int len=0, maxlen=0, maxf=0;
        vector<int> mp(26,0);
        while(j<s.length()){
            mp[s[j] - 'A']++;
            maxf = max(maxf, mp[s[j]-'A']);
            if((j-i+1)-maxf > k){
                mp[s[i]-'A']--;
                maxf = 0;
                for(int m=0;m<26;m++) maxf = max(maxf, mp[m]);
                i++;
            }
            if((j-i+1)-maxf <= k) maxlen = max(maxlen, j-i+1);
            j++;
        }
        return maxlen;
    }
};