class Solution {
public:
    /**
     * @param num: a rotated sorted array
     * @return: the minimum number in the array
     */
    int findMin(vector<int> &num) {
        int target = num[num.size() - 1];
        int low = 0, high = num.size() - 1;
        while (low + 1 < high) {
            int mid = low + (high - low) / 2;
            if (num[mid] > target) {
                low = mid;
            } else {
                high = mid;
            }
        }

        if (num[low] < num[high]) {
            return num[low];
        }
        return num[high];
    }
};
