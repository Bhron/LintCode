// Solution 1
class Solution {
public:
    /**
     * @param n: An integer.
     * return : An array storing 1 to the largest number with n digits.
     */
    vector<int> numbersByRecursion(int n) {
        vector<int> nums;

        if (n <= 0) {
            return nums;
        }

        helper(nums, 1, 10, n);

        return nums;
    }
private:
    void helper(vector<int>& nums, int start, int end, int n) {
        if (n == 0) {
            return;
        }

        int i = start;
        for (i = start; i < end; i++) {
            nums.push_back(i);
        }

        helper(nums, i, end * 10, n - 1);
    }
};

// Solution 2
class Solution {
public:
    /**
     * @param n: An integer.
     * return : An array storing 1 to the largest number with n digits.
     */
    vector<int> numbersByRecursion(int n) {
        vector<int> nums;

        if (n <= 0) {
            return nums;
        }

        helper(nums, 0, n);

        return nums;
    }
private:
    void helper(vector<int>& nums, int num, int n) {
        if (n == 0) {
            if (num > 0) {
                nums.push_back(num);
            }
            return;
        }

        int i;
        for (i = 0; i <= 9; i++) {
            helper(nums, num * 10 + i, n - 1);
        }
    }
};
