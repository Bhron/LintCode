/**
 * Definition of ArrayReader:
 *
 * class ArrayReader {
 * public:
 *     int get(int index) {
 *          // return the number on given index,
 *          // return -1 if index does not exist.
 *     }
 * };
 */
class Solution {
public:
    /**
     * @param reader: An instance of ArrayReader.
     * @param target: An integer
     * @return: An integer which is the first index of target.
     */
    int searchBigSortedArray(ArrayReader *reader, int target) {
        int start = 0, end = 0;
        while (reader->get(end) != -1 && reader->get(end) < target) {
            end = end * 2 + 1;
        }

        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (reader->get(mid) == -1 || reader->get(mid) >= target) {
                end = mid;
            } else {
                start = mid;
            }
        }

        if (reader->get(start) == target) {
            return start;
        }
        if (reader->get(end) == target) {
            return end;
        }
        return -1;
    }
};
