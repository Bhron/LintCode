class Solution {
public:
    /**
     * @param A, B: Two strings.
     * @return: The length of longest common subsequence of A and B.
     */
    int longestCommonSubsequence(string A, string B) {
        if (A.empty() || B.empty()) {
            return 0;
        }

        int A_len = A.length();
        int B_len = B.length();

        int** F = new int*[A_len + 1];
        for (int i = 0; i <= A_len; i++) {
            F[i] = new int[B_len + 1];
        }

        for (int i = 0; i <= A_len; i++) {
            F[i][0] = 0;
        }
        for (int i = 0; i <= B_len; i++) {
            F[0][i] = 0;
        }

        for (int i = 1; i <= A_len; i++) {
            for (int j = 1; j <= B_len; j++) {
                F[i][j] = max(F[i - 1][j], F[i][j - 1]);
                if (A[i - 1] == B[j - 1]) {
                    F[i][j] = max(F[i - 1][j - 1] + 1, F[i][j]);
                }
            }
        }

        int LCS_len = F[A_len][B_len];
        delete F;

        return LCS_len;
    }
};
