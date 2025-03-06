class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size()*grid[0].size();
        unordered_map<int, int> mp(n);
        for(int i=1;i<=n;i++){
            mp[i] = 0;
        }
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                mp[grid[i][j]]++;
            }
        }
        int miss = -1, doub = -1;
        for(auto num:mp){
            if(miss != -1 && doub != -1) break;
            if(num.second == 0) miss = num.first;
            else if(num.second == 2) doub = num.first;
        }
        return {doub, miss};
    }
};