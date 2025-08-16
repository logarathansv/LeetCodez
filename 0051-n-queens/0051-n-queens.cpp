class Solution {
public:
    bool ispos(int r, int c, vector<string>& board){
        int nr = r;
        int nc = c;

        while(nr>=0 && nc>=0){
            if(board[nr][nc] == 'Q') return false;
            nr--;
            nc--;
        }

        nr = r;
        nc = c;

        while(nc>=0){
            if(board[nr][nc] == 'Q') return false;
            nc--;
        }

        nc = c;

        while(nr<board.size() && nc>=0){
            if(board[nr][nc] == 'Q') return false;
            nr++;
            nc--;
        }

        return true;
    }
    void solve(int col, vector<string> &board, vector<vector<string>> &ans, int n){
        if(col == n) {ans.push_back(board);return;}

        for(int r = 0; r<n;r++){
            if(ispos(r, col, board)){
                board[r][col] = 'Q';
                solve(col + 1, board, ans, n);
                board[r][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));

        solve(0, board, ans, n);

        return ans;
    }
};