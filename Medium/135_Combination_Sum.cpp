class Solution {
public:
    /**
     * @param candidates: A list of integers
     * @param target:An integer
     * @return: A list of lists of integers
     */
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        vector<vector<int>> combinations;

        if (candidates.empty()) {
            return combinations;
        }

        sort(candidates.begin(), candidates.end());

        vector<int> cur;

        combination_sum_helper(candidates, target, 0, cur, combinations);

        return combinations;
    }
private:
    void combination_sum_helper(const vector<int> &candidates, int target, int pos, vector<int>& cur, vector<vector<int>>& combinations) {
        if (target == 0) {
            combinations.push_back(vector<int>(cur));
            return;
        }

        int prev = -1;
        for (int i = pos; i < candidates.size(); i++) {
            if (candidates[i] > target) {
                break;
            }

            if (prev != -1 && prev == candidates[i]) {
                continue;
            }

            cur.push_back(candidates[i]);
            combination_sum_helper(candidates, target - candidates[i], i, cur, combinations);
            cur.pop_back();

            prev = candidates[i];
        }
    }
};
