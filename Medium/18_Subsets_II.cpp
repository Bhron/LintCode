// Recursion
class Solution {
public:
    /**
     * @param S: A set of numbers.
     * @return: A list of lists. All valid subsets.
     */
    vector<vector<int> > subsetsWithDup(const vector<int> &S) {
        vector<vector<int>> all_subsets;

        if (S.size() == 0) {
            return all_subsets;
        }

        vector<int> sorted_S(S);
        sort(sorted_S.begin(), sorted_S.end());
        vector<int> init_set;

        subsets_helper(all_subsets, init_set, sorted_S, 0);

        return all_subsets;
    }
private:
    void subsets_helper(vector<vector<int>> &all_subsets, vector<int> &cur_set, const vector<int> &S, int begin) {
        all_subsets.push_back(vector<int>(cur_set));

        for (int i = begin; i < S.size(); i++) {
            if (i != begin && S[i] == S[i - 1]) {
                continue;
            }
            cur_set.push_back(S[i]);
            subsets_helper(all_subsets, cur_set, S, i + 1);
            cur_set.pop_back();
        }
    }
};

// Non-Recursion
class Solution {
public:
    /**
     * @param S: A set of numbers.
     * @return: A list of lists. All valid subsets.
     */
    vector<vector<int> > subsetsWithDup(const vector<int> &S) {
        vector<vector<int>> all_subsets;

        if (S.size() == 0) {
            return all_subsets;
        }

        vector<int> sorted_S(S);
        sort(sorted_S.begin(), sorted_S.end());

        vector<int> cur;
        all_subsets.push_back(cur);

        int start = 0;
        for (int i = 0; i < sorted_S.size(); i++) {
            int n = all_subsets.size();
            for (int j = start; j < n; j++) {
                cur = all_subsets[j];
                cur.push_back(sorted_S[i]);
                all_subsets.push_back(cur);
            }

            if (i < sorted_S.size() - 1 && sorted_S[i + 1] == sorted_S[i]) {
                start = n;
            } else {
                start = 0;
            }
        }

        return all_subsets;
    }
};
