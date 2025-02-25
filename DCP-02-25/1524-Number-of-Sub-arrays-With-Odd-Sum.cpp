class Solution {
public:

    vector<string> stringMatching(vector<string>& words) {
        vector<string> ans;
        for(int i=0;i<words.size();i++){
            for(int j=0;j<words.size();j++){
                if(j!=i && words[j].find(words[i]) != string::npos){
                    ans.push_back(words[i]);
                    break;
                } // find substr in npos, and return the first occurrence if found
            }
        }
        return ans;
    }
};