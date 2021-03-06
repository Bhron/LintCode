class Solution {
public:
    int partitionArray(vector<int> &nums, int k) {
        int i = 0, j = nums.size() - 1;
        while (i < j) {
            while (i <= j && nums[i] < k) {
                i++;
            }
            while (i < j && nums[j] >= k) {
                j--;
            }
            if (i < j) {
                int tmp = nums[i];
                nums[i] = nums[j];
                nums[j] = tmp;
                i++;
                j--;
            }
        }
        return i;
    }
};
