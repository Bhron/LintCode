// Bubble Sort, Time Complexity O(n^2)
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

// Selection Sort, Time Complexity O(n^2)
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
                if (A[j] > A[A.size() - 1 - i]) {
                    swap(A[j], A[A.size() - 1 - i]);
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

// Insertion Sort, Time Complexity O(n^2)
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

        for (int i = 1; i < A.size(); i++) {
            int val = A[i], j;
            for (j = i - 1; j >= 0 && A[j] > val; j--) {
                A[j + 1] = A[j];
            }
            A[j + 1] = val;
        }
    }
private:
    void swap(int& a, int& b) {
        int tmp = a;
        a = b;
        b = tmp;
    }
};
