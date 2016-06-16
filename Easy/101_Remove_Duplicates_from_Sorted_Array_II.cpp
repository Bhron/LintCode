class Solution {
public:
    /**
     * @param A: a list of integers
     * @return : return an integer
     */
    int removeDuplicates(vector<int> &nums) {
        if (nums.size() <= 2) {
            return nums.size();
        }

        int i = 0, len = 0;
        while (i < nums.size()) {
            int val = nums[i], j;
            for (j = i; j < nums.size() && nums[j] == val; j++) {
                if (j - i < 2) {
                    nums[len++] = val;
                }
            }
            i = j;
        }

        return len;
    }
};
