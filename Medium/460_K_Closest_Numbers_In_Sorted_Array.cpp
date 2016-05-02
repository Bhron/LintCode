class Solution {
public:
    /**
     * @param A an integer array
     * @param target an integer
     * @param k a non-negative integer
     * @return an integer array
     */
    vector<int> kClosestNumbers(vector<int>& A, int target, int k) {
        vector<int> nums;

        if (A.empty() || k <= 0) {
            return nums;
        }

        int index = find_target(A, target);

        for (int i = 0, start = index, end = index + 1; i < k && (start >= 0 || end < A.size()); i++) {
            if (start < 0) {
                nums.push_back(A[end++]);
            } else if (end >= A.size()) {
                nums.push_back(A[start--]);
            } else {
                if (target - A[start] <= A[end] - target) {
                    nums.push_back(A[start--]);
                } else {
                    nums.push_back(A[end++]);
                }
            }
        }

        return nums;
    }
private:
    int find_target(const vector<int>& A, int target) {
        int start = 0, end = A.size() - 1;
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (A[mid] >= target) {
                end = mid;
            } else {
                start = mid;
            }
        }

        if (A[end] <= target) {
            return end;
        }
        if (A[start] <= target) {
            return start;
        }
        return 0;
    }
};
