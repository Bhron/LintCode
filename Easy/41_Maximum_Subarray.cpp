class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: A integer indicate the sum of max subarray
     */
    int maxSubArray(vector<int> nums) {
        if (nums.empty()) {
            return 0;
        }

        int min_prefix_sum = 0;
        int largest_sum = INT_MIN;
        int prefix_sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            prefix_sum += nums[i];
            largest_sum = max(prefix_sum - min_prefix_sum, largest_sum);
            min_prefix_sum = min(prefix_sum, min_prefix_sum);
        }

        return largest_sum;
    }
};
