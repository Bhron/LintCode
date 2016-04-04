class Solution {
public:
    /**
     * @param A: An integer array.
     * @param B: An integer array.
     * @return: a double whose format is *.5 or *.0
     */
    double findMedianSortedArrays(vector<int> A, vector<int> B) {
        if (A.empty() && B.empty()) {
            return 0;
        }

        int size = A.size() + B.size();

        if (size % 2 == 1) {
            return find_Kth(A, 0, B, 0, size / 2 + 1);
        } else {
            return (find_Kth(A, 0, B, 0, size / 2) + find_Kth(A, 0, B, 0, size / 2 + 1)) / 2.0;
        }
    }
private:
    int find_Kth(vector<int>& A, int A_start, vector<int>& B, int B_start, int k) {
        if (A_start >= A.size()) {
            return B[B_start + k - 1];
        }
        if (B_start >= B.size()) {
            return A[A_start + k - 1];
        }
        if (k == 1) {
            return min(A[A_start], B[B_start]);
        }

        int A_val = A_start + k / 2 - 1 < A.size() ? A[A_start + k / 2 - 1] : INT_MAX;
        int B_val = B_start + k / 2 - 1 < B.size() ? B[B_start + k / 2 - 1] : INT_MAX;

        if (A_val < B_val) {
            return find_Kth(A, A_start + k / 2, B, B_start, k - k / 2);
        } else {
            return find_Kth(A, A_start, B, B_start + k / 2, k - k / 2);
        }
    }
};
