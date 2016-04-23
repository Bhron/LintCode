class Solution {
public:
    /**
     * @param A an integer array sorted in ascending order
     * @param target an integer
     * @return an integer
     */
    int totalOccurrence(vector<int>& A, int target) {
        if (A.empty()) {
            return 0;
        }

        int start = 0, end = A.size() - 1;
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (A[mid] >= target) {
                end = mid;
            } else {
                start = mid;
            }
        }

        int start_index;
        if (A[start] == target) {
            start_index = start;
        } else if (A[end] == target) {
            start_index = end;
        } else {
            return 0;
        }

        start = 0, end = A.size() - 1;
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (A[mid] <= target) {
                start = mid;
            } else {
                end = mid;
            }
        }

        int end_index;
        if (A[end] == target) {
            end_index = end;
        } else if (A[start] == target) {
            end_index = start;
        }

        return end_index - start_index + 1;
    }
};
