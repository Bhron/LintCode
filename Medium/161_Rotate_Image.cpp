class Solution {
public:
    /**
     * @param matrix: A list of lists of integers
     * @return: Void
     */
    void rotate(vector<vector<int> > &matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return;
        }

        int n = matrix.size();

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        for (int i = 0; i < n; i++) {
            reverse(begin(matrix[i]), end(matrix[i]));
        }
    }
private:
    void swap(int& a, int& b) {
        int tmp = a;
        a = b;
        b = tmp;
    }
};
