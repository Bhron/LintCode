// Recursion
class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: A list of unique permutations.
     */
    vector<vector<int> > permuteUnique(vector<int> &nums) {
        vector<vector<int> > permutations;

        if (nums.size() == 0) {
            return permutations;
        }

        sort(nums.begin(), nums.end());

        vector<int> init;
        vector<bool> selected(nums.size(), false);

        helper(permutations, init, selected, nums);

        return permutations;
    }
private:
    void helper(vector<vector<int> > &permutations, vector<int> &cur, vector<bool> &selected, const vector<int> &nums) {
        if (cur.size() == nums.size()) {
            permutations.push_back(vector<int>(cur));
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (selected[i] || (i > 0 && nums[i] == nums[i - 1] && !selected[i - 1])) {
                continue;
            }

            cur.push_back(nums[i]);
            selected[i] = true;
            helper(permutations, cur, selected, nums);
            cur.pop_back();
            selected[i] = false;
        }
    }
};

// Non-Recursion
class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: A list of unique permutations.
     */
    vector<vector<int> > permuteUnique(vector<int> &nums) {
        vector<vector<int>> permutations;

        if (nums.size() == 0) {
            return permutations;
        }

        sort(nums.begin(), nums.end());

        vector<bool> selected(nums.size(), false);
        vector<int> stack;

        int n = nums.size();
        stack.push_back(-1);

        while (!stack.empty()) {
            int last = stack.back();
            stack.pop_back();
            if (last != -1) {
                selected[last] = false;
            }

            // Find the next avaiable number
            int next = -1;
            for (int i = last + 1; i < n; i++) {
                if (selected[i] || (i > 0 && nums[i] == nums[i - 1] && !selected[i - 1])) {
                    continue;
                }

                next = i;
                break;
            }
            if (next == -1) {
                continue;
            }

            // Get the next permutation
            stack.push_back(next);
            selected[next] = true;
            for (int i = 0; i < n; i++) {
                if (!selected[i]) {
                    stack.push_back(i);
                    selected[i] = true;
                }
            }

            vector<int> permutation;
            for (int i = 0; i < n; i++) {
                permutation.push_back(nums[stack[i]]);
            }
            permutations.push_back(permutation);
        }

        return permutations;
    }
};
