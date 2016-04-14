// Dynamic Programming
class Solution {
public:
    /**
     * @param A: A list of lists of integers
     * @return: An integer
     */
    int jump(vector<int> A) {
        if (A.empty()) {
            return -1;
        }

        int n = A.size();
        int F[n];

        F[0] = 0;
        for (int i = 1; i < n; i++) {
            F[i] = INT_MAX;
            for (int j = 0; j < i; j++) {
                if (F[j] != INT_MAX && j + A[j] >= i) {
                    F[i] = F[j] + 1;
                    break;
                }
            }
        }

        return F[n - 1];
    }
};

// Greedy
class Solution {
public:
    /**
     * @param A: A list of lists of integers
     * @return: An integer
     */
    int jump(vector<int> A) {
        if (A.empty()) {
            return -1;
        }

        int start = 0, end = 0, jumps = 0;
        while (end < A.size() - 1) {
            jumps++;
            int farthest = end;
            for (int i = start; i <= end; i++) {
                if (A[i] + i > farthest) {
                    farthest = A[i] + i;
                }
            }
            start = end + 1;
            end = farthest;
        }

        return jumps;
    }
};
