class Solution {
public:
    int dr[4] = {0, 1, 0, -1};
    int dc[4] = {1, 0, -1, 0};
    bool check(int indi, int indj, int ind, string& word,
               vector<vector<char>>& board) {
        if(word[ind] != board[indi][indj]) return false;
        if(ind == word.size()-1) return true;

        char temp = board[indi][indj];
        board[indi][indj] = '#';

        for (int i = 0; i < 4; i++) {
            int nr = indi + dr[i];
            int nc = indj + dc[i];
            if (nr < board.size() && nr > -1 && nc < board[0].size() &&
                nc > -1 && board[nr][nc] != '#') {
                if (check(nr, nc, ind + 1, word, board))
                    return true;
            }
        }

        board[indi][indj] = temp;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (word[0] == board[i][j] && check(i, j, 0, word, board))
                    return true;
            }
        }

        return false;
    }
};