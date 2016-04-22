class Solution {
public:
    /**
     * @param nums: The integer array.
     * @param target: Target number to find.
     * @return: The first position of target. Position starts from 0.
     */
    int binarySearch(vector<int> &array, int target) {
        if (array.empty()) {
            return -1;
        }

        int low = 0, high = array.size() - 1;

        while (low + 1 < high) {
            int mid = low + (high - low) / 2;
            if (array[mid] == target) {
                high = mid;
            } else if (array[mid] < target) {
                low = mid;
            } else {
                high = mid;
            }
        }

        if (array[low] == target) {
            return low;
        }
        if (array[high] == target) {
            return high;
        }

        return -1;
    }
};
