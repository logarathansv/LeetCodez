class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        if(word1.size() < word2.size()) return {};
        vector<int> ans;
        vector<int> last(word2.size(), -1);
        int j = word2.size()-1;

        for(int i=word1.size()-1;i>=0;i--){
            if(j >= 0 && word1[i] == word2[j]){
                last[j] = i;
                j--;
            }
        }
        j = 0;
        int skip = 0;
        for(int i=0;i<word1.size();i++){
            if(j == word2.size()) break;
            if(word1[i] == word2[j] ||
                (skip == 0 && (j == word2.size()-1 || i < last[j+1]))){
                    skip += (word1[i] != word2[j]) ? 1: 0;
                    ans.push_back(i);
                    j++;
                }
        }

        return j == word2.size() ? ans : vector<int>();
    }
};