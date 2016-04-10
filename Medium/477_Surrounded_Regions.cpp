// BFS
class Solution {
public:
    /**
     * @param board a 2D board containing 'X' and 'O'
     * @return void
     */
    void surroundedRegions(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty()) {
            return;
        }

        n = board.size(), m = board[0].size();

        for (int i = 0; i < n; i++) {
            bfs(board, i, 0);
            bfs(board, i, m - 1);
        }
        for (int i = 1; i < m - 1; i++) {
            bfs(board, 0, i);
            bfs(board, n - 1, i);
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                } else if (board[i][j] == 'C') {
                    board[i][j] = 'O';
                }
            }
        }
    }
private:
    int n, m;

    class Pair {
    public:
        int x;
        int y;

        Pair(int x, int y) {
            this->x = x;
            this->y = y;
        }
    };

    void bfs(vector<vector<char>>& board, int x, int y) {
        if (board[x][y] != 'O') {
            return;
        }

        board[x][y] = 'C';

        queue<Pair> q;
        q.push(Pair(x, y));

        while (!q.empty()) {
            Pair p = q.front();
            q.pop();

            static const int dx[4] = { -1, 1, 0, 0 };
            static const int dy[4] = { 0, 0, -1, 1 };
            for (int i = 0; i < 4; i++) {
                int nx = p.x + dx[i];
                int ny = p.y + dy[i];
                if (0 <= nx && nx < n && 0 <= ny && ny < m && board[nx][ny] == 'O') {
                    board[nx][ny] = 'C';
                    q.push(Pair(nx, ny));
                }
            }
        }
    }
};

// Union Find
class Solution {
public:
    /**
     * @param board a 2D board containing 'X' and 'O'
     * @return void
     */
    void surroundedRegions(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty()) {
            return;
        }

        n = board.size(), m = board[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'O') {
                    int id = get_id(i, j, m);
                    parents[id] = id;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'O') {
                    helper(board, i, j);
                }
            }
        }

        for (int i = 0; i < n; i++) {
            check_boundary(board, i, 0);
            check_boundary(board, i, m - 1);
        }
        for (int i = 1; i < m - 1; i++) {
            check_boundary(board, 0, i);
            check_boundary(board, n - 1, i);
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'O') {
                    int id = get_id(i, j, m);
                    int parent = find(id);
                    if (hash.find(parent) == hash.end()) {
                        board[i][j] = 'X';
                    }
                }
            }
        }

        parents.clear();
        hash.clear();
    }
private:
    int n, m;
    unordered_map<int, int> parents;
    unordered_set<int> hash;

    class Pair {
    public:
        int x;
        int y;

        Pair(int x, int y) {
            this->x = x;
            this->y = y;
        }
    };

    void helper(vector<vector<char>>& board, int x, int y) {
        int id = get_id(x, y, m);

        static const int dx[4] = { -1, 1, 0, 0 };
        static const int dy[4] = { 0, 0, -1, 1 };

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (0 <= nx && nx < n && 0 <= ny && ny < m && board[nx][ny] == 'O') {
                int nid = get_id(nx, ny, m);
                merge(id, nid);
            }
        }
    }

    void check_boundary(vector<vector<char>>& board, int x, int y) {
        if (board[x][y] == 'O') {
            int id = get_id(x, y, m);
            int parent = find(id);
            if (hash.find(parent) == hash.end()) {
                hash.insert(parent);
            }
        }
    }

    int get_id(int x, int y, int m) {
        return x * m + y;
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
};
