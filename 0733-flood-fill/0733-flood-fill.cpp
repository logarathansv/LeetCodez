class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();

        int tocolor = image[sr][sc]; 

        int rows[] = {0, -1, 0, 1, 0};
        int cols[] = {0, 0 ,1, 0, -1};

        queue<pair<int, int>> q;
        q.push({sr, sc});

        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for(int i=0;i<5;i++){
                int nr = r + rows[i];
                int nc = c + cols[i];
                if(nr >= 0 && nr < n && nc >= 0 && nc < m && image[nr][nc] == tocolor && image[nr][nc] != color){
                    image[nr][nc] = color;
                    q.push({nr, nc});
                }
            }
        }
        return image;
    }
};