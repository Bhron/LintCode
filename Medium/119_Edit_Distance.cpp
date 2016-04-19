class Solution {
public:
    /**
     * @param word1 & word2: Two string.
     * @return: The minimum number of steps.
     */
    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();

        int** F = new int*[n + 1];
        for (int i = 0; i <= n; i++) {
            F[i] = new int[m + 1];
        }

        for (int i = 0; i <= n; i++) {
            F[i][0] = i;
        }
        for (int i = 0; i <= m; i++) {
            F[0][i] = i;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                int tmp = min(F[i][j - 1] + 1, F[i - 1][j] + 1);
                if (word1[i - 1] == word2[j - 1]) {
                    F[i][j] = min(F[i - 1][j - 1], tmp);
                } else {
                    F[i][j] = min(F[i - 1][j - 1] + 1, tmp);
                }
            }
        }

        int min_steps = F[n][m];
        delete F;

        return min_steps;
    }
};
