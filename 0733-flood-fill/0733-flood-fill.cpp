class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        queue<pair<int,int>> q;

        q.push({sr, sc});
        int actual = image[sr][sc];
        if(color == actual) return image;

        image[sr][sc] = color;

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        while(!q.empty()){
            auto front = q.front();
            q.pop();

            for(int k=0;k<4;k++){
                int nr = dr[k] + front.first;
                int nc = dc[k] + front.second;
                if(nr >=0 && nc >=0 && nr < image.size() && nc <image[0].size() && image[nr][nc] == actual){
                    q.push({nr, nc});
                    image[nr][nc] = color;
                }
            }
        }

        return image;
    }
};