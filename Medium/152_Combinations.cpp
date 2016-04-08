class Solution {
public:
    /**
     * @param n: Given the range of numbers
     * @param k: Given the numbers of combinations
     * @return: All the combinations of k numbers out of 1..n
     */
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int>> combinations;

        if (n <= 0 || k <= 0 || k > n) {
            return combinations;
        }

        vector<int> nums;
        for (int i = 1; i <= n; i++) {
            nums.push_back(i);
        }

        vector<int> cur;
        helper(combinations, cur, 0, nums, k);

        return combinations;
    }
private:
    void helper(vector<vector<int>>& combinations, vector<int>& cur, int pos, const vector<int>& nums, int k) {
        if (cur.size() == k) {
            combinations.push_back(cur);
            return;
        }

        for (int i = pos; i < nums.size(); i++) {
            cur.push_back(nums[i]);
            helper(combinations, cur, i + 1, nums, k);
            cur.pop_back();
        }
    }
};
