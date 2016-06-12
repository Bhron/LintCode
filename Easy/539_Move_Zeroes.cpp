class Solution {
public:
    /**
     * @param nums an integer array
     * @return nothing, do this in-place
     */
    void moveZeroes(vector<int>& nums) {
        if (nums.empty()) {
            return;
        }

        int i = 0, j = 0;
        while (i < nums.size()) {
            if (nums[i] != 0) {
                nums[j++] = nums[i];
            }
            i++;
        }

        while (j < nums.size()) {
            nums[j++] = 0;
        }
    }
};
