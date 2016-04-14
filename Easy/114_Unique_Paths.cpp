class Solution {
public:
    /**
     * @param n, m: positive integer (1 <= n ,m <= 100)
     * @return an integer
     */
    int uniquePaths(int m, int n) {
        if (m <= 0 || n <= 0) {
            return 0;
        }

        int** F = new int*[m];
        for (int i = 0; i < m; i++) {
            F[i] = new int[n];
        }

        for (int i = 0; i < n; i++) {
            F[0][i] = 1;
        }
        for (int i = 0; i < m; i++) {
            F[i][0] = 1;
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                F[i][j] = F[i - 1][j] + F[i][j - 1];
            }
        }

        int unique_paths = F[m - 1][n - 1];
        delete F;

        return unique_paths;
    }
};
