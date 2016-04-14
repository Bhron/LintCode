class Solution {
public:
    /**
     * @param n: An integer
     * @return: An integer
     */
    int climbStairs(int n) {
        if (n < 0) {
            return 0;
        }

        int F[n + 1];

        F[0] = 1, F[1] = 1;

        for (int i = 2; i <= n; i++) {
            F[i] = F[i - 2] + F[i - 1];
        }

        return F[n];
    }
};
