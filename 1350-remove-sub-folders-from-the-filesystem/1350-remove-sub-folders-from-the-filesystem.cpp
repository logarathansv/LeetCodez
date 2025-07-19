class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        vector<string> ans;
        ans.push_back(folder[0]);
        for(int j=1;j<folder.size();j++){
            string fol = ans.back();
            fol.push_back('/');

            if(folder[j].compare(0, fol.size(), fol) != 0) ans.push_back(folder[j]);
        }
        return ans;
    }
};