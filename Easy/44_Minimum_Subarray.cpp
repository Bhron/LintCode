class Solution {
public:
    /**
     * @param nums: a list of integers
     * @return: A integer denote the sum of minimum subarray
     */
    int minSubArray(vector<int> nums) {
        if (nums.empty()) {
            return 0;
        }

        int smallest_sum = INT_MAX;
        int prefix_sum = 0;
        int max_prefix_sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            prefix_sum += nums[i];
            smallest_sum = min(smallest_sum, prefix_sum - max_prefix_sum);
            max_prefix_sum = max(max_prefix_sum, prefix_sum);
        }

        return smallest_sum;
    }
};
