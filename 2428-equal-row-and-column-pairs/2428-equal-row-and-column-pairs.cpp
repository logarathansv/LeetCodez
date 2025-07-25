class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        string s = "", s2 = "";
        unordered_map<string, int> mp, mp2;
        vector<string> str;

        int ct = 0, ct2 = 0;
        
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                s += to_string(grid[i][j])+"_";
            }
            for(int j=0;j<grid[0].size();j++){
                s2 += to_string(grid[j][i])+"_";
            }

            cout<<s<<" "<<s2<<'\n';

            mp[s]++;
            str.push_back(s);
            mp2[s2]++;

            s = "";
            s2 = "";
        }

        for(auto ele:str) 
            if(mp2.find(ele) != mp2.end()) ct += mp2[ele];

        return max(ct, ct2);
    }
};