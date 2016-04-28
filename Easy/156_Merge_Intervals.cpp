/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 */
class Solution {
public:
    /**
     * @param intervals: interval list.
     * @return: A new interval list.
     */
    vector<Interval> merge(vector<Interval> &intervals) {
        if (intervals.empty()) {
            return intervals;
        }

        sort(intervals.begin(), intervals.end(), compare);

        int new_size = intervals.size();
        for (int i = 0, j = 1; j < intervals.size(); j++) {
            if (intervals[j].start <= intervals[i].end) {
                intervals[i].end = max(intervals[i].end, intervals[j].end);
                new_size--;
            } else {
                i++;
                intervals[i] = intervals[j];
            }
        }

        int old_size = intervals.size();
        for (int j = 0; j < old_size - new_size; j++) {
            intervals.pop_back();
        }

        return intervals;
    }
private:
    static bool compare(const Interval& a, const Interval& b) {
        return a.start < b.start;
    }
};
