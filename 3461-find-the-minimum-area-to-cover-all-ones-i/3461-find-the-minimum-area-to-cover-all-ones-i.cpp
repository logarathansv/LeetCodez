class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int maxi = 0, mini = grid.size();
        int maxj = 0, minj = grid[0].size();
        int ct = 0;

        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j] == 1) {
                    mini = min(mini, i);
                    minj = min(minj, j);
                    maxi = max(maxi, i);
                    maxj = max(maxj, j);
                }
            }
        }

        return (maxi - mini + 1) * (maxj - minj + 1);
    }
};