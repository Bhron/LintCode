class Solution {
public:
    /**
     * @param nums: An array of integers
     * @return: An array of integers that's previous permuation
     */
    vector<int> previousPermuation(vector<int> &nums) {
        vector<int> result;

        if (nums.empty()) {
            return result;
        }

        result = vector<int>(nums);

        int i;
        for (i = result.size() - 2; i >= 0 && result[i] <= result[i + 1]; i--) {
            ;
        }

        if (i < 0) {
            reverse(result, 0, result.size() - 1);
            return result;
        }

        int j;
        for (j = result.size() - 1; j > i && result[j] >= result[i]; j--) {
            ;
        }

        int tmp = result[i];
        result[i] = result[j];
        result[j] = tmp;
        reverse(result, i + 1, result.size() - 1);

        return result;
    }
private:
    void reverse(vector<int>& nums, int start, int end) {
        while (start < end) {
            int tmp = nums[start];
            nums[start] = nums[end];
            nums[end] = tmp;
            start++;
            end--;
        }
    }
};
