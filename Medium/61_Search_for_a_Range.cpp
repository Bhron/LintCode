class Solution {
    /**
     *@param A : an integer sorted array
     *@param target :  an integer to be inserted
     *return : a list of length 2, [index1, index2]
     */
public:
    vector<int> searchRange(vector<int> &A, int target) {
        vector<int> positions(2, -1);

        if (A.empty()) {
            return positions;
        }

        int low, high;

        /* Find the starting position */
        low = 0, high = A.size() - 1;
        while (low + 1 < high) {
            int mid = low + (high - low) / 2;
            if (A[mid] == target) {
                high = mid;
            } else if (A[mid] < target) {
                low = mid;
            } else {
                high = mid;
            }
        }
        if (A[low] == target) {
            positions[0] = low;
        } else if (A[high] == target) {
            positions[0] = high;
        } else {
            return positions;
        }

        /* Find the ending position */
        low = 0, high = A.size() - 1;
        while (low + 1 < high) {
            int mid = low + (high - low) / 2;
            if (A[mid] == target) {
                low = mid;
            } else if (A[mid] < target) {
                low = mid;
            } else {
                high = mid;
            }
        }
        if (A[high] == target) {
            positions[1] = high;
        } else if (A[low] == target) {
            positions[1] = low;
        }

        return positions;
    }
};
