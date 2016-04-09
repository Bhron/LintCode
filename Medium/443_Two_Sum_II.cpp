class Solution {
public:
    /**
     * @param nums: an array of integer
     * @param target: an integer
     * @return: an integer
     */
    int twoSum2(vector<int> &nums, int target) {
        if (nums.empty()) {
            return 0;
        }

        sort(nums.begin(), nums.end());

        int counter = 0;
        int start = 0, end = nums.size() - 1;
        while (start < end) {
            int sum = nums[start] + nums[end];

            if (sum <= target) {
                start++;
            } else {
                counter += end - start;
                end--;
            }
        }

        return counter;
    }
};
