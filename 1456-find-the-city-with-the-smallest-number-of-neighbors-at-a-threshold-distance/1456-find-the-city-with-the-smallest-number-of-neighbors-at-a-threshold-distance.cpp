class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        int mini = INT_MAX, ans = -1;

        vector<vector<int>> mat(n, vector<int>(n, INT_MAX));

        for(int i=0;i<n;i++){
            mat[i][i] = 0;
        }

        for(int i=0;i<edges.size();i++){
            mat[edges[i][0]][edges[i][1]] = edges[i][2];
            mat[edges[i][1]][edges[i][0]] = edges[i][2];
        }

        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    mat[i][j] = min((long long)mat[i][j], (long long)mat[i][k] + mat[k][j]);
                }
            }
        }
        int reach = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j] <= distanceThreshold){
                    reach++;
                }
                cout<<mat[i][j]<<" ";
            }
            cout<<'\n';
            if(mini >= reach){
                ans = i;
                mini = reach;
            }
            reach = 0;
        }

        return ans;
    }
};