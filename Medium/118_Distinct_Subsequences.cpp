// O(n * m) Space
class Solution {
public:
    /**
     * @param S, T: Two string.
     * @return: Count the number of distinct subsequences
     */
    int numDistinct(string &S, string &T) {
        int n = S.length();
        int m = T.length();

        int** F = new int*[n + 1];
        for (int i = 0; i <= n; i++) {
            F[i] = new int[m + 1];
        }

        for (int i = 0; i <= n; i++) {
            F[i][0] = 1;
        }
        for (int i = 1; i <= m; i++) {
            F[0][i] = 0;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (S[i - 1] == T[j - 1]) {
                    F[i][j] = F[i - 1][j - 1] + F[i - 1][j];
                } else {
                    F[i][j] = F[i - 1][j];
                }
            }
        }

        int distinct_subsequences = F[n][m];
        delete F;

        return distinct_subsequences;
    }
};
