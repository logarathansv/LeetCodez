class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        if(k == 0) return grid;

        k = k % (grid.size() * grid[0].size());

        while(k--){
            for(int i=grid.size()-1;i>=0;i--){
                for(int j=grid[i].size()-1;j>=0;j--){
                    if(j > 0)
                        swap(grid[i][j], grid[i][j-1]);
                }
                if(i>0)
                swap(grid[i][0], grid[i-1][grid[0].size()-1]);
            }
        }

        return grid;
    }
};