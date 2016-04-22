class Solution {
    /**
     * param A : an integer sorted array
     * param target :  an integer to be inserted
     * return : an integer
     */
public:
    int searchInsert(vector<int> &A, int target) {
        if (A.empty()) {
            return 0;
        }

        int low = 0, high = A.size() - 1;
        while (low + 1 < high) {
            int mid = low + (high - low) / 2;
            if (A[mid] == target) {
                high = mid;
            } else if (A[mid] > target) {
                high = mid;
            } else {
                low = mid;
            }
        }

        if (A[low] >= target) {
            return low;
        }
        if (A[high] >= target) {
            return high;
        }
        return high + 1;
    }
};
