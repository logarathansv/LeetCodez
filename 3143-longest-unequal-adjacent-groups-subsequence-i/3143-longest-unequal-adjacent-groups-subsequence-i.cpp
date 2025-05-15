class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        if(groups.size() == 1) return {words[0]};

        vector<string> ans;
        vector<string> lev;
        bool f = 0;

        for(int i = 0;i < words.size();i++){
            f = groups[i];
            for(int j=i;j<words.size();j++){
                if(f == groups[j]) lev.push_back(words[j]);
                else continue;
                f = !f;
            }
            if(ans.size() < lev.size()){
                ans = lev;
            }
            lev.clear();
        }

        return ans;
    }
};