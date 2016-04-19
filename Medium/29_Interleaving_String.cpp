class Solution {
public:
    /**
     * Determine whether s3 is formed by interleaving of s1 and s2.
     * @param s1, s2, s3: As description.
     * @return: true of false.
     */
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.length();
        int m = s2.length();

        if (n + m != s3.length()) {
            return false;
        }

        bool** F = new bool*[n + 1];
        for (int i = 0; i <= n; i++) {
            F[i] = new bool[m + 1];
        }

        F[0][0] = true;
        for (int i = 1; i <= n; i++) {
            F[i][0] = s1[i - 1] == s3[i - 1] && F[i - 1][0];
        }
        for (int i = 1; i <= m; i++) {
            F[0][i] = s2[i - 1] == s3[i - 1] && F[0][i - 1];
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                F[i][j] = (s1[i - 1] == s3[i + j - 1] && F[i - 1][j])
                       || (s2[j - 1] == s3[i + j - 1] && F[i][j - 1]);
            }
        }

        bool is_formed = F[n][m];
        delete F;

        return is_formed;
    }
};
