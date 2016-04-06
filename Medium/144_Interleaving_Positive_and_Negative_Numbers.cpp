class Solution {
public:
    /**
     * @param A: An integer array.
     * @return: void
     */
    void rerange(vector<int> &A) {
        int i = 0, j = A.size() - 1;
        while (i < j) {
            while (i <= j && A[i] < 0) {
                i++;
            }
            while (i < j && A[j] >= 0) {
                j--;
            }
            if (i < j) {
                swap(A[i], A[j]);
                i++;
                j--;
            }
        }

        int negative_num = i;
        int positive_num = A.size() - negative_num;
        int diff = abs(negative_num - positive_num);

        if (negative_num > positive_num) {
            i = i - 1, j = A.size() - 1;
            for (int k = 0;  k < diff; k++) {
                swap(A[i--], A[j--]);
            }

            j--;
            i = 1;
        } else {
            j = A.size() - 1 - diff;
            i = 0;
        }

        while (i < j) {
            swap(A[i], A[j]);
            i += 2;
            j -= 2;
        }
    }
};


class Solution {
public:
    /**
     * @param A: An integer array.
     * @return: void
     */
    void rerange(vector<int> &A) {
        int negative_num = 0, positive_num = 0;
        for (int i = 0; i < A.size(); i++) {
            if (A[i] < 0) {
                negative_num++;
            } else {
                positive_num++;
            }
        }

        int negative_index = 0, positive_index = 1;
        if (positive_num > negative_num) {
            negative_index = 1;
            positive_index = 0;
        }

        while (negative_index < A.size() && positive_index < A.size()) {
            while (negative_index < A.size() && A[negative_index] < 0) {
                negative_index += 2;
            }
            while (positive_index < A.size() && A[positive_index] >= 0) {
                positive_index += 2;
            }
            if (negative_index < A.size() && positive_index < A.size()) {
                swap(A[negative_index], A[positive_index]);
                negative_index += 2;
                positive_index += 2;
            }
        }
    }
};
