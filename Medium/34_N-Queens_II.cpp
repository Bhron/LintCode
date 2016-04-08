class Solution {
public:
    /**
     * Calculate the total number of distinct N-Queen solutions.
     * @param n: The number of queens.
     * @return: The total number of distinct solutions.
     */
    int totalNQueens(int n) {
        solutions_num = 0;

        if (n <= 0) {
            return solutions_num;
        }

        vector<int> cols;
        helper(n, cols);

        return solutions_num;
    }
private:
    int solutions_num;

    void helper(int n, vector<int>& cols) {
        if (cols.size() == n) {
            solutions_num++;
            return;
        }

        for (int i = 0; i < n; i++) {
            if (!is_valid(cols, i)) {
                continue;
            }

            cols.push_back(i);
            helper(n, cols);
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
};
