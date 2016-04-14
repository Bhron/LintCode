class Solution {
public:
    /**
     * @param grid: a list of lists of integers.
     * @return: An integer, minimizes the sum of all numbers along its path
     */
    int minPathSum(vector<vector<int> > &grid) {
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }

        int m = grid.size();
        int n = grid[0].size();

        int** F = new int*[m];
        for (int i = 0; i < m; i++) {
            F[i] = new int[n];
        }

        F[0][0] = grid[0][0];
        for (int i = 1; i < n; i++) {
            F[0][i] = F[0][i - 1] + grid[0][i];
        }
        for (int i = 1; i < m; i++) {
            F[i][0] = F[i - 1][0] + grid[i][0];
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                F[i][j] = min(F[i - 1][j], F[i][j - 1]) + grid[i][j];
            }
        }

        int min_sum = F[m - 1][n - 1];
        delete F;

        return min_sum;
    }
};
