class Solution {
public:
    /**
      * @param board: the board
      * @return: wether the Sudoku is valid
      */
    bool isValidSudoku(const vector<vector<char>>& board) {
        if (board.size() != 9 || board[0].size() != 9) {
            return false;
        }

        for (int i = 0; i < 9; i++) {
            vector<bool> visited(9, false);
            for (int j = 0; j < 9; j++) {
                if (check(visited, board[i][j]) == false) {
                    return false;
                }
            }
        }

        for (int i = 0; i < 9; i++) {
            vector<bool> visited(9, false);
            for (int j = 0; j < 9; j++) {
                if (check(visited, board[j][i]) == false) {
                    return false;
                }
            }
        }

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                vector<bool> visited(9, false);
                for (int k = 0; k < 9; k++) {
                    if (check(visited, board[i * 3 + k / 3][j * 3 + k % 3]) == false) {
                        return false;
                    }
                }
            }
        }

        return true;
    }
private:
    bool check(vector<bool>& visited, char cell) {
        if (cell == '.') {
            return true;
        }

        if (cell < '1' || cell > '9') {
            return false;
        }

        int index = cell - '1';
        if (visited[index]) {
            return false;
        }

        visited[index] = true;

        return true;
    }
};
