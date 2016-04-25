class Solution {
    /**
     * param A : an integer ratated sorted array
     * param target :  an integer to be searched
     * return : an integer
     */
public:
    int search(vector<int> &A, int target) {
        if (A.empty()) {
            return -1;
        }

        int low = 0, high = A.size() - 1;
        while (low + 1 < high) {
            int mid = low + (high - low) / 2;
            if (A[mid] == target) {
                return mid;
            }
            if (A[mid] > A[low]) {
                if (A[low] <= target && target <= A[mid]) {
                    high = mid;
                } else {
                    low = mid;
                }
            } else {
                if (A[mid] <= target && target <= A[high]) {
                    low = mid;
                } else {
                    high = mid;
                }
            }
        }

        if (A[low] == target) {
            return low;
        }
        if (A[high] == target) {
            return high;
        }
        return -1;
    }
};
