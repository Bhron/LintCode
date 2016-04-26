class Solution {
public:
    /**
     * @param matrix: A list of lists of integers
     * @param target: An integer you want to search in matrix
     * @return: An integer indicate the total occurrence of target in the given matrix
     */
    int searchMatrix(vector<vector<int> >& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) {
            return 0;
        }

        int m = matrix.size(), n = matrix[0].size();
        int occurrence = 0;

        // From the bottom left to the up right
        int x = m - 1, y = 0;
        while (x >= 0 && y < n) {
            if (matrix[x][y] == target) {
                occurrence++;
                x--;
                y++;
            } else if (matrix[x][y] < target) {
                y++;
            } else {
                x--;
            }
        }

        return occurrence;
    }
};
