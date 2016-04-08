// Recursion
class Solution {
public:
    /**
     * Get all distinct N-Queen solutions
     * @param n: The number of queens
     * @return: All distinct solutions
     * For example, A string '...Q' shows a queen on forth position
     */
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string>> solutions;

        if (n <= 0) {
            return solutions;
        }

        vector<int> cols;
        helper(n, cols, solutions);

        return solutions;
    }
private:
    void helper(int n, vector<int>& cols, vector<vector<string>>& solutions) {
        if (cols.size() == n) {
            generate_solution(cols, solutions);
            return;
        }

        for (int i = 0; i < n; i++) {
            if (!is_valid(cols, i)) {
                continue;
            }

            cols.push_back(i);
            helper(n, cols, solutions);
            cols.pop_back();
        }
    }

    bool is_valid(vector<int>& cols, int col) {
        int rows = cols.size();

        for (int i = 0; i < rows; i++) {
            // Same column
            if (cols[i] == col) {
                return false;
            }
            // Left-Top to Right-Bottom
            if (i - cols[i] == rows - col) {
                return false;
            }
            // Right-Top to Left-Bottom
            if (i + cols[i] == rows + col) {
                return false;
            }
        }

        return true;
    }

    void generate_solution(const vector<int>& cols, vector<vector<string>>& solutions) {
        vector<string> solution;

        int n = cols.size();
        for (int i = 0; i < n; i++) {
            string row = "";
            for (int j = 0; j < cols.size(); j++) {
                if (j == cols[i]) {
                    row += "Q";
                } else {
                    row += ".";
                }
            }
            solution.push_back(row);
        }

        solutions.push_back(solution);
    }
};

// Non-Recursion
class Solution {
public:
    /**
     * Get all distinct N-Queen solutions
     * @param n: The number of queens
     * @return: All distinct solutions
     * For example, A string '...Q' shows a queen on forth position
     */
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string>> solutions;

        if (n <= 0) {
            return solutions;
        }

        vector<int> cols;

        cols.push_back(0);
        bool found = true;
        int last;

        while (!cols.empty()) {
            if (!found) {
                last = cols.back();
                cols.pop_back();
            } else {
                last = -1;
            }

            found = false;

            if (cols.size() == n) {
                generate_solution(cols, solutions);
                continue;
            }

            for (int i = last + 1; i < n; i++) {
                if (!is_valid(cols, i)) {
                    continue;
                }

                cols.push_back(i);
                found = true;
                break;
            }
        }

        return solutions;
    }
private:
    bool is_valid(vector<int>& cols, int col) {
        int rows = cols.size();

        for (int i = 0; i < rows; i++) {
            // Same column
            if (cols[i] == col) {
                return false;
            }
            // Left-Top to Right-Bottom
            if (i - cols[i] == rows - col) {
                return false;
            }
            // Right-Top to Left-Bottom
            if (i + cols[i] == rows + col) {
                return false;
            }
        }

        return true;
    }

    void generate_solution(const vector<int>& cols, vector<vector<string>>& solutions) {
        vector<string> solution;

        int n = cols.size();
        for (int i = 0; i < n; i++) {
            string row = "";
            for (int j = 0; j < cols.size(); j++) {
                if (j == cols[i]) {
                    row += "Q";
                } else {
                    row += ".";
                }
            }
            solution.push_back(row);
        }

        solutions.push_back(solution);
    }
};
