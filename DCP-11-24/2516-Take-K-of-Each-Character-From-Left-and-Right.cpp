class Solution {
public:
    int takeCharacters(string s, int k) {
        vector<int> fq(3,0);

        for(int i=0;i<s.length();i++){
            fq[s[i] - 'a']++;
        }
        if(fq[0] > k-1 && fq[1] > k-1 && fq[2] > k-1){
            int l = 0, maxlen = INT_MIN;

            vector<int> curr(3,0);
            for(int r=0;r<s.length();r++){
                curr[s[r]-'a']++;
                while(l<=r && (curr[0]>fq[0]-k || curr[1]>fq[1]-k || curr[2]>fq[2]-k)){
                    curr[s[l]-'a']--;
                    l++;
                }
                maxlen = max(maxlen, r-l+1);
            }

            return s.length() - maxlen;
        }
        else return -1;
    }
};