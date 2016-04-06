class Solution {
public:
    /**
     * @param numbers: Give an array numbers of n integer
     * @param target: An integer
     * @return: return the sum of the three integers, the sum closest target.
     */
    int threeSumClosest(vector<int> nums, int target) {
        if (nums.empty()) {
            return INT_MAX;
        }

        sort(nums.begin(), nums.end());

        int closest_sum = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            int start = i + 1, end = nums.size() - 1;
            while (start < end) {
                int sum = nums[i] + nums[start] + nums[end];
                if (sum == target) {
                    return sum;
                } else if (sum < target) {
                    start++;
                } else {
                    end--;
                }

                if (abs(target - sum) < abs(target - closest_sum)) {
                    closest_sum = sum;
                }
            }
        }

        return closest_sum;
    }
};
