class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @return: return nothing (void), do not return anything, modify nums in-place instead
     */
    void nextPermutation(vector<int> &nums) {
        if (nums.empty()) {
            return;
        }

        int i;
        for (i = nums.size() - 2; i >= 0 && nums[i] >= nums[i + 1]; i--) {
            ;
        }

        if (i < 0) {
            reverse(nums, 0, nums.size() -1);
            return;
        }

        int j;
        for (j = nums.size() - 1; j > i && nums[j] <= nums[i]; j--) {
            ;
        }

        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;

        reverse(nums, i + 1, nums.size() - 1);
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
