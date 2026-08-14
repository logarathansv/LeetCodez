class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> matrix(n, vector<int>(n, 1e9));

        for(auto i:edges){
            matrix[i[0]][i[1]] = i[2];
            matrix[i[1]][i[0]] = i[2];
        }

        for(int via=0;via<n;via++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(matrix[i][via] == 1e9 || matrix[via][j] == 1e9) continue;
                    matrix[i][j] = min(matrix[i][j], matrix[i][via] + matrix[via][j]);
                }
            }
        }

        int maxi = INT_MAX, city = -1;
         for(int i=0;i<n;i++){
            int ct = 0;
            for(int j=0;j<n;j++){
                if(i == j || matrix[i][j] == 1e9 || matrix[i][j] > distanceThreshold){
                    continue;
                } 
                ct++;
            }
            if(ct <= maxi) {city = i;maxi = ct;}
        }

        return city;
    }
};