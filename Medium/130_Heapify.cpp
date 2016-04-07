class Solution {
public:
    /**
     * @param A: Given an integer array
     * @return: void
     */
    void heapify(vector<int> &A) {
        for (int i = 0; i < A.size(); i++) {
            siftup(A, i);
        }
    }
private:
    void siftup(vector<int>& A, int k) {
        while (k != 0) {
            int parent = (k - 1) / 2;

            if (A[k] > A[parent]) {
                break;
            }

            int tmp = A[k];
            A[k] = A[parent];
            A[parent] = tmp;

            k = parent;
        }
    }
};


