class Solution {
public:
    /**
     * @param A and B: sorted integer array A and B.
     * @return: A new sorted integer array
     */
    vector<int> mergeSortedArray(vector<int> &A, vector<int> &B) {
        int n = A.size();
        int m = B.size();

        vector<int> result;

        int i, j;
        for (i = 0, j = 0; i < n && j < m; ) {
            if (A[i] < B[j]) {
                result.push_back(A[i++]);
            } else {
                result.push_back(B[j++]);
            }
        }

        while (i < n) {
            result.push_back(A[i++]);
        }
        while (j < m) {
            result.push_back(B[j++]);
        }

        return result;
    }
};
