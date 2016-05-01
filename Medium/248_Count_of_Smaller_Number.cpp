class Solution {
public:
   /**
     * @param A: An integer array
     * @return: The number of element in the array that
     *          are smaller that the given integer
     */
    vector<int> countOfSmallerNumber(vector<int> &A, vector<int> &queries) {
        vector<int> result;

        if (queries.empty()) {
            return result;
        }
        if (A.empty()) {
            return vector<int>(queries.size(), 0);
        }

        sort(A.begin(), A.end());

        for (int i = 0; i < queries.size(); i++) {
            int target = queries[i];

            int start = 0, end = A.size() - 1;
            while (start + 1 < end) {
                int mid = start + (end - start) / 2;
                if (A[mid] >= target) {
                    end = mid;
                } else {
                    start = mid;
                }
            }

            if (A[end] < target) {
                result.push_back(end + 1);
            } else if (A[start] < target) {
                result.push_back(start + 1);
            } else {
                result.push_back(0);
            }
        }

        return result;
    }
};
