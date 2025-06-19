class Solution {
public:
    int findmin(int i, int j, vector<vector<int>>& tri, vector<vector<int>>& memo){
        if(i == tri.size()-1) {
            return tri[i][j];
        }
        // if(i > tri.size()-1) return INT_MAX;
        // if(j > tri[i].size()-1) return INT_MAX;

        if(memo[i][j] != -1) return memo[i][j];

        memo[i][j] = min(findmin(i+1, j, tri, memo), findmin(i+1, j+1, tri, memo)) + tri[i][j];

        return memo[i][j];
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int m = triangle[n-1].size();

        vector<vector<int>> memo(n, vector<int>(m, -1));
        return findmin(0, 0, triangle, memo);
    }
};