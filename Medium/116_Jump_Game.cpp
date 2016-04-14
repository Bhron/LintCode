// Dynamic Programming
class Solution {
public:
    /**
     * @param A: A list of integers
     * @return: The boolean answer
     */
    bool canJump(vector<int> A) {
        if (A.empty()) {
            return false;
        }

        int n = A.size();
        bool F[n];

        F[0] = true;
        for (int i = 1; i < n; i++) {
            F[i] = false;
            for (int j = 0; j < i; j++) {
                if (F[j] && j + A[j] >= i) {
                    F[i] = true;
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
     * @param A: A list of integers
     * @return: The boolean answer
     */
    bool canJump(vector<int> A) {
        if (A.empty()) {
            return false;
        }

        int n = A.size();

        int farthest = A[0];
        for (int i = 1; i < n; i++) {
            if (farthest >= i && A[i] + i > farthest) {
                farthest = A[i] + i;
            }
        }

        return farthest >= n - 1;
    }
};
