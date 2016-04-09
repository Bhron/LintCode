class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: The median of numbers
     */
    vector<int> medianII(vector<int> &nums) {
        vector<int> medians;

        if (nums.empty()) {
            return medians;
        }

        priority_queue<int> max_heap;
        priority_queue<int, std::vector<int>, std::greater<int>> min_heap;

        int median = nums[0];
        medians.push_back(median);

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < median) {
                max_heap.push(nums[i]);
            } else {
                min_heap.push(nums[i]);
            }

            if (max_heap.size() > min_heap.size()) {
                min_heap.push(median);
                median = max_heap.top();
                max_heap.pop();
            } else if (max_heap.size() + 1 < min_heap.size()) {
                max_heap.push(median);
                median = min_heap.top();
                min_heap.pop();
            }

            medians.push_back(median);
        }

        return medians;
    }
};
