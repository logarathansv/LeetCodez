class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int ct = 0;
            for(int i=0;i<words.size();i++){
                for(int j=i+1;j<words.size();j++){
                    int n = words[i].size();
                    int m = words[j].size();
                    if(words[j].find(words[i]) == 0 
                        && words[j].substr(m-n, n) == words[i]){
                            ct++;
                        }
                }
            }
        return ct;
    }
};