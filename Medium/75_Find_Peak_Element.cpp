class Solution {
public:
    /**
     * @param A: An integers array.
     * @return: return any of peek positions.
     */
    int findPeak(vector<int> A) {
        int low = 1, high = A.size() - 2;
        while (low + 1 < high) {
            int mid = low + (high - low) / 2;
            if (A[mid] < A[mid + 1]) {
                low = mid;
            } else if (A[mid] > A[mid + 1]) {
                high = mid;
            } else {
                high = mid;
            }
        }

        if (A[low] > A[high]) {
            return low;
        }
        return high;
    }
};
