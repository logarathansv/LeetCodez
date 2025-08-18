class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        vector<string> strs2 = strs;

        for(auto &str : strs2){
            sort(str.begin(), str.end());
        }

        unordered_map<string, vector<string>> mp;

        for(int i=0;i<strs2.size();i++){
            mp[strs2[i]].push_back(strs[i]); 
        }

        for(auto ele:mp){
            ans.push_back(ele.second);
        }

        return ans;
    }
};