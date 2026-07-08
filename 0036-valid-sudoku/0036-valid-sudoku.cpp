class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row[9][9] = {0};
        int col[9][9] = {0};
        int grid[9][9] = {0};
        int number=0;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == '.') {
                    continue;
                }
                number = board[i][j] - '0';
                int k = i / 3 * 3 + j / 3;
                if (row[i][number - 1]++ || col[j][number - 1]++ ||
                    grid[k][number - 1]++) {
                    return false;
                }
            }
        }
        return true;
    }
};