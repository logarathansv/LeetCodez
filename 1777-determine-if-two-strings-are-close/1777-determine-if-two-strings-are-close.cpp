class Solution {
public:
    static bool cmp(const pair<int, int> &a, const pair<int, int> &b){
        return a.second < b.second;
    }
    bool closeStrings(string word1, string word2) {
        unordered_map<int, int> mp, mp2;
        if(word1.size() != word2.size()) return false;

        for(auto w:word1) mp[w]++;
        for(auto w:word2) mp2[w]++;

        for(auto w:word1){
            if(mp2.find(w) == mp2.end()) return false;
        }
        for(auto w:word2){
            if(mp.find(w) == mp.end()) return false;
        }

        vector<pair<int, int>> pr, pr2;
        for(auto ele:mp){
            pr.push_back(ele);
        }
        for(auto ele:mp2){
            pr2.push_back(ele);
        }

        sort(pr.begin(), pr.end(), cmp);
        sort(pr2.begin(), pr2.end(), cmp);

        for(int i=0;i<pr.size();i++){
            if(pr[i].second != pr2[i].second) return false;
        }

        return true;
    }
};