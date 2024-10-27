#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int totalSquares = 0;
        
        // Count all 1x1 squares directly
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == 1) {
                    totalSquares++;  
                    int maxSize = min(rows - i, cols - j); 
                    for (int k = 2; k <= maxSize; k++) {
                        bool isSquare = true;
                        for (int m = i; m < i + k && isSquare; m++) {
                            for (int n = j; n < j + k; n++) {
                                if (matrix[m][n] == 0) {
                                    isSquare = false;
                                    break;
                                }
                            }
                        }
                        if (isSquare) {
                            totalSquares++;
                        } else {
                            break; 
                        }
                    }
                }
            }
        }
        
        return totalSquares;
    }
};
