// Bubble Sort
class Solution {
public:
    /**
     * @param A an integer array
     * @return void
     */
    void sortIntegers(vector<int>& A) {
        if (A.empty()) {
            return;
        }

        for (int i = 0; i < A.size() - 1; i++) {
            for (int j = 0; j < A.size() - 1 - i; j++) {
                if (A[j] > A[j + 1]) {
                    swap(A[j], A[j + 1]);
                }
            }
        }
    }
private:
    void swap(int& a, int& b) {
        int tmp = a;
        a = b;
        b = tmp;
    }
};
