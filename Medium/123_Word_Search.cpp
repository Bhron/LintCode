class Solution {
public:
    /**
     * @param board: A list of lists of character
     * @param word: A string
     * @return: A boolean
     */
    bool exist(vector<vector<char> > &board, string word) {
        if (word.empty()) {
            return true;
        }

        if (board.empty() || board[0].empty()) {
            return false;
        }

        vector<vector<bool>> visited;
        for (int i = 0; i < board.size(); i++) {
            vector<bool> row(board[0].size(), false);
            visited.push_back(row);
        }

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == word[0]) {
                    bool found = helper(board, word, visited, 0, i, j);

                    if (found) {
                        return true;
                    }
                }
            }
        }

        return false;
    }
private:
    bool helper(vector<vector<char>> &board, const string& word, vector<vector<bool>>& visited, int pos, int x, int y) {
        if (board[x][y] != word[pos]) {
            return false;
        }

        if (pos == word.length() - 1) {
            return true;
        }

        visited[x][y] = true;

        if (x - 1 >= 0 && !visited[x - 1][y]) {
            if (helper(board, word, visited, pos + 1, x - 1, y)) {
                return true;
            }
        }

        if (x + 1 < board.size() && !visited[x + 1][y]) {
            if (helper(board, word, visited, pos + 1, x + 1, y)) {
                return true;
            }
        }

        if (y - 1 >= 0 && !visited[x][y - 1]) {
            if (helper(board, word, visited, pos + 1, x, y - 1)) {
                return true;
            }
        }

        if (y + 1 < board[0].size() && !visited[x][y + 1]) {
            if (helper(board, word, visited, pos + 1, x, y + 1)) {
                return true;
            }
        }

        visited[x][y] = false;

        return false;
    }
};
