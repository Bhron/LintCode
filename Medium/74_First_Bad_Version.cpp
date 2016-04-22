/**
 * class VersionControl {
 *     public:
 *     static bool isBadVersion(int k);
 * }
 * you can use VersionControl::isBadVersion(k) to judge whether
 * the kth code version is bad or not.
*/
class Solution {
public:
    /**
     * @param n: An integers.
     * @return: An integer which is the first bad version.
     */
    int findFirstBadVersion(int n) {
        int low = 1, high = n;
        while (low + 1 < high) {
            int mid = low + (high -low) / 2;
            if (VersionControl::isBadVersion(mid)) {
                high = mid;
            } else {
                low = mid;
            }
        }

        if (VersionControl::isBadVersion(low)) {
            return low;
        }
        return high;
    }
};
