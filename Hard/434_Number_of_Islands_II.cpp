/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    /**
     * @param n an integer
     * @param m an integer
     * @param operators an array of point
     * @return an integer array
     */
    vector<int> numIslands2(int n, int m, vector<Point>& operators) {
        vector<int> island_nums;

        if (n <= 0 || m <= 0 || operators.empty()) {
            return island_nums;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int id = get_id(i, j, m);
                parents[id] = id;
            }
        }

        vector<vector<int>> islands;
        for (int i = 0; i < n; i++) {
            vector<int> row(m, 0);
            islands.push_back(row);
        }

        int counter = 0;
        for (int i = 0; i < operators.size(); i++) {
            int x = operators[i].x;
            int y = operators[i].y;
            if (islands[x][y] != 1) {
                helper(islands, x, y, n, m, counter);
            }

            island_nums.push_back(counter);
        }

        parents.clear();

        return island_nums;
    }
private:
    unordered_map<int, int> parents;

    void helper(vector<vector<int>>& islands, int x, int y, int n, int m, int& counter) {
        counter++;
        islands[x][y] = 1;

        int id = get_id(x, y, m);
        int parent = find(id);

        static const int dx[4] = { -1, 1, 0, 0 };
        static const int dy[4] = { 0, 0, -1, 1 };

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (0 <= nx & nx < n && 0 <= ny && ny < m && islands[nx][ny] == 1) {
                int nid = get_id(nx, ny, m);
                int parent_n = find(nid);
                if (parent != parent_n) {
                    counter--;
                    merge(id, nid);
                }
            }
        }
    }

    int find(int x) {
        int parent = x;
        while (parent != parents[parent]) {
            parent = parents[parent];
        }

        int root = parent, tmp;
        parent = x;
        while (parent != parents[parent]) {
            tmp = parents[parent];
            parents[parent] = root;
            parent = tmp;
        }

        return root;
    }

    void merge(int a, int b) {
        int parent_a = find(a);
        int parent_b = find(b);

        if (parent_a != parent_b) {
            parents[parent_b] = parent_a;
        }
    }

    int get_id(int x, int y, int m) {
        return x * m + y;
    }
};
