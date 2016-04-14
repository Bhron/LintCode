// Up-Bottom Dynamic Programming
class Solution {
public:
    /**
     * @param triangle: a list of lists of integers.
     * @return: An integer, minimum path sum.
     */
    int minimumTotal(vector<vector<int> > &triangle) {
        if (triangle.empty()) {
            return 0;
        }

        int n = triangle.size();
        int** F = new int*[n];
        for (int i = 0; i < n; i++) {
            F[i] = new int[triangle[i].size()];
        }

        F[0][0] = triangle[0][0];

        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                F[i][j] = INT_MAX;
                if (j - 1 >= 0) {
                    F[i][j] = min(F[i][j], F[i - 1][j - 1]);
                }
                if (j < triangle[i - 1].size()) {
                    F[i][j] = min(F[i][j], F[i - 1][j]);
                }
                F[i][j] += triangle[i][j];
            }
        }

        int min_sum = INT_MAX;
        for (int i = 0; i < triangle[n - 1].size(); i++) {
            min_sum = min(min_sum, F[n - 1][i]);
        }
        delete F;

        return min_sum;
    }
};

// Bottom-Up Dynamic Programming
class Solution {
public:
    /**
     * @param triangle: a list of lists of integers.
     * @return: An integer, minimum path sum.
     */
    int minimumTotal(vector<vector<int> > &triangle) {
        if (triangle.empty()) {
            return 0;
        }

        int n = triangle.size();
        int** F = new int*[n];
        for (int i = 0; i < n; i++) {
            F[i] = new int[triangle[i].size()];
        }

        for (int i = 0; i < triangle[n - 1].size(); i++) {
            F[n - 1][i] = triangle[n - 1][i];
        }

        for (int i = n - 2; i >= 0; i--) {
            for (int j = 0; j <= i; j++) {
                F[i][j] = min(F[i + 1][j], F[i + 1][j + 1]) + triangle[i][j];
            }
        }

        int min_sum = F[0][0];
        delete F;

        return min_sum;
    }
};

// Memorization Search
class Solution {
private:
    int** min_sum;
    bool** calculated;
    int n;
public:
    /**
     * @param triangle: a list of lists of integers.
     * @return: An integer, minimum path sum.
     */
    int minimumTotal(vector<vector<int> > &triangle) {
        if (triangle.empty()) {
            return 0;
        }

        n = triangle.size();
        min_sum = new int*[n];
        calculated = new bool*[n];
        for (int i = 0; i < n; i++) {
            min_sum[i] = new int[triangle[i].size()];
            calculated[i] = new bool[triangle[i].size()];
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < triangle[i].size(); j++) {
                calculated[i][j] = false;
            }
        }

        return minimum_total_helper(triangle, 0, 0);
    }
private:
    int minimum_total_helper(vector<vector<int> >& triangle, int x, int y) {
        if (x == n) {
            return 0;
        }

        if (calculated[x][y]) {
            return min_sum[x][y];
        }

        min_sum[x][y] = min(minimum_total_helper(triangle, x + 1, y), minimum_total_helper(triangle, x + 1, y + 1)) + triangle[x][y];
        calculated[x][y] = true;

        return min_sum[x][y];
    }
};
