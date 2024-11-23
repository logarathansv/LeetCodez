class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int rows = box.size();
        int cols = box[0].size();

        // Initialize result with rotated dimensions
        vector<vector<char>> result(cols, vector<char>(rows, '.'));

        // Rotate the box 90 degrees clockwise
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result[j][rows - i - 1] = box[i][j];
            }
        }

        for (int col = 0; col < rows; ++col) {
            int emptyRow = cols - 1; 
            for (int row = cols - 1; row >= 0; --row) { 
                if (result[row][col] == '*') {
                    emptyRow = row - 1; 
                } else if (result[row][col] == '#') {
                    swap(result[row][col], result[emptyRow][col]);
                    --emptyRow; 
                }
            }
        }

        /*for(int i=0;i<result[0].size();i++){
            int l=0;
            int r=result.size()-1;
            while(l<r){
                while(l<result.size()){
                    if(result[l][i] == '#'){
                        break;
                    }
                    l++;
                }
                if(l == result.size()) break;
                int temp = r;
                while(temp > -1){
                    if(result[temp][i] == '*'){
                        r = temp;
                    }
                    temp--;
                }
                while(l<r){ 
                    if(result[r][i] == '.'){
                        swap(result[l][i], result[r][i]);
                        break;
                    }
                    r--;
                }
            }
        }*/
        return result;
    }
};