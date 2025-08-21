class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int ct = 0;
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> res(n, vector<int>(m, 0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(j == 0) res[i][j] = mat[i][j];
                else {
                    if(mat[i][j] == 0) res[i][j] = 0;
                    else res[i][j] = res[i][j-1] + 1;
                }

                int curr = res[i][j];

                for(int k=i;k>=0;k--){
                    curr = min(curr, res[k][j]);
                    if(curr == 0) break;
                    ct += curr;
                }
            }
        }

        return ct;
    }
};