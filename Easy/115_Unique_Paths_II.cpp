class Solution {
public:
    /**
     * @param obstacleGrid: A list of lists of integers
     * @return: An integer
     */
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        if (obstacleGrid.empty() || obstacleGrid[0].empty()) {
            return 0;
        }

        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        int** F = new int*[m];
        for (int i = 0; i < m; i++) {
            F[i] = new int[n];
        }

        F[0][0] = obstacleGrid[0][0] == 0 ? 1 : 0;
        for (int i = 1; i < n; i++) {
            F[0][i] = F[0][i - 1] > 0 && obstacleGrid[0][i] == 0 ? 1 : 0;
        }
        for (int i = 1; i < m; i++) {
            F[i][0] = F[i - 1][0] > 0 && obstacleGrid[i][0] == 0 ? 1 : 0;
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (obstacleGrid[i][j] == 0) {
                    F[i][j] = F[i - 1][j] + F[i][j - 1];
                } else {
                    F[i][j] = 0;
                }
            }
        }

        int unique_paths = F[m - 1][n - 1];
        delete F;

        return unique_paths;
    }
};
