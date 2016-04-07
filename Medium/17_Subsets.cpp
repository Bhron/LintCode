// Recursion
class Solution {
public:
    /**
     * @param S: A set of numbers.
     * @return: A list of lists. All valid subsets.
     */
    vector<vector<int>> subsets(vector<int> &nums) {
        vector<vector<int>> all_subsets;

        if (nums.size() == 0) {
            return all_subsets;
        }

        sort(nums.begin(), nums.end());
        vector<int> init_set;

        subsets_helper(all_subsets, init_set, nums, 0);

        return all_subsets;
    }
private:
    void subsets_helper(vector<vector<int>> &all_subsets, vector<int> &cur_set, vector<int> &nums, int begin) {
        all_subsets.push_back(vector<int>(cur_set));

        for (int i = begin; i < nums.size(); i++) {
            cur_set.push_back(nums[i]);
            subsets_helper(all_subsets, cur_set, nums, i + 1);
            cur_set.pop_back();
        }
    }
};

// Non-Recursion  Array
class Solution {
public:
    /**
     * @param S: A set of numbers.
     * @return: A list of lists. All valid subsets.
     */
    vector<vector<int>> subsets(vector<int> &nums) {
        vector<vector<int>> all_subsets;

        if (nums.size() == 0) {
            return all_subsets;
        }

        sort(nums.begin(), nums.end());

        vector<int> cur;
        all_subsets.push_back(cur);

        for (int i = 0; i < nums.size(); i++) {
            int n = all_subsets.size();
            for (int j = 0; j < n; j++) {
                cur = all_subsets[j];
                cur.push_back(nums[i]);
                all_subsets.push_back(cur);
            }
        }

        return all_subsets;
    }
};

// Non-Recursion  Bit Manipulation
class Solution {
public:
    /**
     * @param S: A set of numbers.
     * @return: A list of lists. All valid subsets.
     */
    vector<vector<int>> subsets(vector<int> &nums) {
        vector<vector<int>> all_subsets;

        if (nums.size() == 0) {
            return all_subsets;
        }

        sort(nums.begin(), nums.end());

        int n = nums.size();
        unsigned long subsets_num = 1UL << n;

        for (unsigned long i = 0 ; i < subsets_num; i++) {
            vector<int> subset;
            for (int j = 0; j < n; j++) {
                if ((i & (1UL << j)) != 0) {
                    subset.push_back(nums[j]);
                }
            }
            all_subsets.push_back(subset);
        }

        return all_subsets;
    }
};
