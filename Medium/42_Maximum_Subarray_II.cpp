class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: An integer denotes the sum of max two non-overlapping subarrays
     */
    int maxTwoSubArrays(vector<int> nums) {
        if (nums.empty()) {
            return 0;
        }

        vector<int> left_max_subarray_sum(nums.size(), 0);
        vector<int> right_max_subarray_sum(nums.size(), 0);

        int prefix_sum = 0;
        int min_prefix_sum = 0;
        int max_subarray_sum = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            prefix_sum += nums[i];
            max_subarray_sum = max(max_subarray_sum, prefix_sum - min_prefix_sum);
            min_prefix_sum = min(min_prefix_sum, prefix_sum);
            left_max_subarray_sum[i] = max_subarray_sum;
        }

        prefix_sum = 0;
        min_prefix_sum = 0;
        max_subarray_sum = INT_MIN;
        for (int i = nums.size() - 1; i >= 0; i--) {
            prefix_sum += nums[i];
            max_subarray_sum = max(max_subarray_sum, prefix_sum - min_prefix_sum);
            min_prefix_sum = min(min_prefix_sum, prefix_sum);
            right_max_subarray_sum[i] = max_subarray_sum;
        }

        int largest_sum = INT_MIN;
        for (int i = 0; i < nums.size() - 1; i++) {
            largest_sum = max(largest_sum, left_max_subarray_sum[i] + right_max_subarray_sum[i + 1]);
        }

        return largest_sum;
    }
};
