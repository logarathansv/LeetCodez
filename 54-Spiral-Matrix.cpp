class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int startr = 0;
        int startc = 0;
        int endr = matrix.size() - 1;
        int endc = matrix[0].size() - 1;

        vector<int> ans;

        while(startc <= endc && startr <= endr){
            for(int i=startc;i<=endc;i++){
                ans.push_back(matrix[startr][i]);
            }
            startr++;
            for(int i=startr;i<=endr;i++){
                ans.push_back(matrix[i][endc]);
            }
            endc--;
            if(startr <= endr){
                for(int i=endc;i>=startc;i--){
                    ans.push_back(matrix[endr][i]);
                }
                endr--;
            }
            if(startc <= endc){
                for(int i=endr;i>=startr;i--){
                    ans.push_back(matrix[i][startc]);
                }
                startc++;
            }
        }
        return ans;
    }
};