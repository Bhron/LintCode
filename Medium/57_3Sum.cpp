class Solution {
public:
    /**
     * @param numbers : Give an array numbers of n integer
     * @return : Find all unique triplets in the array which gives the sum of zero.
     */
    vector<vector<int> > threeSum(vector<int> &nums) {
        vector<vector<int>> triplets;

        if (nums.empty()) {
            return triplets;
        }

        sort(nums.begin(), nums.end());

        int len = nums.size();
        for (int i = 0; i < len - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            int a = nums[i];
            int start = i + 1, end = len - 1;
            while (start < end) {
                if (start > i + 1 && nums[start] == nums[start - 1]) {
                    start++;
                    continue;
                }

                int sum = nums[start] + nums[end];
                if (sum == -a) {
                    triplets.push_back(vector<int>{a, nums[start], nums[end]});
                    start++;
                    end--;
                } else if (sum < -a) {
                    start++;
                } else {
                    end--;
                }
            }
        }

        return triplets;
    }
};
