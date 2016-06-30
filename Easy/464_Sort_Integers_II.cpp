// Merge Sort, Time Complexity O(nlogn)
class Solution {
public:
    /**
     * @param A an integer array
     * @return void
     */
    void sortIntegers2(vector<int>& A) {
        if (A.empty()) {
            return;
        }

        mergeSort(A, 0, A.size() - 1);
    }
private:
    void mergeSort(vector<int>& A, int start, int end) {
        if (start >= end) {
            return;
        }
        int mid = start + (end - start) / 2;

        mergeSort(A, start, mid);
        mergeSort(A, mid + 1, end);

        // Merge
        vector<int> tmp;
        int i = start, j = mid + 1;
        while (i <= mid && j <= end) {
            if (A[i] < A[j]) {
                tmp.push_back(A[i++]);
            } else {
                tmp.push_back(A[j++]);
            }
        }

        while (i <= mid) {
            tmp.push_back(A[i++]);
        }
        while (j <= end) {
            tmp.push_back(A[j++]);
        }

        i = start, j = 0;
        while (j < tmp.size()) {
            A[i++] = tmp[j++];
        }
    }
};
