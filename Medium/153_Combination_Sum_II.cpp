class Solution {
public:
    /**
     * @param num: Given the candidate numbers
     * @param target: Given the target number
     * @return: All the combinations that sum to target
     */
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        vector<vector<int>> combinations;

        if (num.empty()) {
            return combinations;
        }

        sort(num.begin(), num.end());

        vector<int> cur;

        combination_sum_2_helper(num, target, 0, cur, combinations);

        return combinations;
    }
private:
    void combination_sum_2_helper(const vector<int> &num, int target, int pos, vector<int>& cur, vector<vector<int>>& combinations) {
        if (target == 0) {
            combinations.push_back(vector<int>(cur));
            return;
        }

        int prev = -1;
        for (int i = pos; i < num.size(); i++) {
            if (num[i] > target) {
                break;
            }

            if (prev != -1 && num[i] == prev) {
                continue;
            }

            cur.push_back(num[i]);
            combination_sum_2_helper(num, target - num[i], i + 1, cur, combinations);
            cur.pop_back();

            prev = num[i];
        }
    }
};
