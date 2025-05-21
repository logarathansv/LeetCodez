class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<int> rowMark(matrix.size(), 0);
        vector<int> colMark(matrix[0].size(), 0);

        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j] == 0) {
                    rowMark[i] = 1;
                    colMark[j] = 1;
                }
            }
        }

        for(int i=0;i<matrix.size();i++){
            if(rowMark[i] == 1){
                for(int j=0;j<matrix[0].size();j++){
                    matrix[i][j] = 0;
                }
            }
        }

        for(int i=0;i<matrix[0].size();i++){
            if(colMark[i] == 1){
                for(int j=0;j<matrix.size();j++){
                    matrix[j][i] = 0;
                }
            }
        }
    }
};