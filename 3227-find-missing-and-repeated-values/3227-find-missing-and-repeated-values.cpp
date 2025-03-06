class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size() * grid[0].size();
        int acsum = 0, exsum= (n*(n+1))/2;
        long long sqsum = 0; 
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                acsum += grid[i][j];
                sqsum += grid[i][j]*grid[i][j];
            }
        }
        long long eq1 = acsum - exsum;
        long long eq2 = (sqsum - ((long long)n*(n+1)*(2*n+1))/6)/(eq1);
        int doub = (eq1+eq2) / 2;
        int miss = doub - eq1;
        return {doub, miss};
    }
};