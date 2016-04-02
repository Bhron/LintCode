class Solution {
public:
    void recoverRotatedSortedArray(vector<int> &nums) {
        int n = nums.size();
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                reverse(nums, 0, i);
                reverse(nums, i + 1, n - 1);
                reverse(nums, 0, n - 1);
                break;
            }
        }
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
