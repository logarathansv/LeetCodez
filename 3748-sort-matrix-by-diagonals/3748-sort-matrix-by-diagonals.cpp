class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        for(int i=0;i<grid.size();i++){
            vector<int> neww;

            int j = i;
            for(int k=0;k<grid.size() - i;k++){ 
                neww.push_back(grid[j++][k]);
            }

            j = i;
            sort(neww.begin(), neww.end(), greater<int>());

            for(int k=0;k<grid.size()- i ;k++){
                grid[j++][k] = neww[k];
            }
        }

        for(int i=1;i<grid.size();i++){
            vector<int> neww;

            int j = i;
            for(int k=0;k<grid.size() - i;k++){ 
                neww.push_back(grid[k][j++]);
            }

            j = i;
            sort(neww.begin(), neww.end());

            for(int k=0;k<grid.size()- i ;k++){
                grid[k][j++] = neww[k];
            }
        }

        return grid;
    }
};