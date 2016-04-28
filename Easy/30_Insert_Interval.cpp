/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */
class Solution {
public:
    /**
     * Insert newInterval into intervals.
     * @param intervals: Sorted interval list.
     * @param newInterval: new interval.
     * @return: A new interval list.
     */
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        vector<Interval> result;

        if (intervals.empty()) {
            result.push_back(newInterval);
            return result;
        }

        int insert_index = 0;
        for (int i = 0; i < intervals.size(); i++) {
            if (intervals[i].end < newInterval.start) {
                result.push_back(intervals[i]);
                insert_index++;
            } else if (intervals[i].start > newInterval.end) {
                result.push_back(intervals[i]);
            } else {
                newInterval.start = min(newInterval.start, intervals[i].start);
                newInterval.end = max(newInterval.end, intervals[i].end);
            }
        }

        auto it = result.begin();
        result.insert(it + insert_index, newInterval);

        return result;
    }
};
