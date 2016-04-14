// Dynamic Programming
class Solution {
public:
    /**
     * @param nums: The integer array
     * @return: The length of LIS (longest increasing subsequence)
     */
    int longestIncreasingSubsequence(vector<int> nums) {
        if (nums.empty()) {
            return 0;
        }

        int n = nums.size();
        int F[n];

        int max_len = 0;
        for (int i = 0; i < n; i++) {
            F[i] = 1;
            for (int j = 0; j < i; j++) {
                if (nums[j] <= nums[i]) {
                    F[i] = max(F[i], F[j] + 1);
                }
            }
            if (F[i] > max_len) {
                max_len = F[i];
            }
        }

        return max_len;
    }
};
