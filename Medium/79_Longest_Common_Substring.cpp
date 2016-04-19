class Solution {
public:
    /**
     * @param A, B: Two string.
     * @return: the length of the longest common substring.
     */
    int longestCommonSubstring(string &A, string &B) {
        if (A.empty() || B.empty()) {
            return 0;
        }

        int n = A.length();
        int m = B.length();

        int** F = new int*[n + 1];
        for (int i = 0; i <= n; i++) {
            F[i] = new int[m + 1];
        }

        for (int i = 0; i <= n; i++) {
            F[i][0] = 0;
        }
        for (int i = 0; i <= m; i++) {
            F[0][i] = 0;
        }

        int LCS_len = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (A[i - 1] == B[j - 1]) {
                    F[i][j] = F[i - 1][j - 1] + 1;
                    LCS_len = max(F[i][j], LCS_len);
                } else {
                    F[i][j] = 0;
                }
            }
        }

        delete F;

        return LCS_len;
    }
};
