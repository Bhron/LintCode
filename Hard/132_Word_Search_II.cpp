class Solution {
private:
    class TrieNode {
    public:
        bool has_word;
        TrieNode* next[26];

        TrieNode() {
            has_word = false;
            for (int i = 0; i < 26; i++) {
                next[i] = NULL;
            }
        }
    };

    TrieNode* root;
public:
    /**
     * @param board: A list of lists of character
     * @param words: A list of string
     * @return: A list of string
     */
    vector<string> wordSearchII(vector<vector<char> > &board, vector<string> &words) {
        vector<string> existing_words;

        if (board.empty() || board[0].empty() || words.empty()) {
            return existing_words;
        }

        root = new TrieNode();
        for (int i = 0; i < words.size(); i++) {
            add_word(words[i]);
        }

        vector<vector<bool>> visited;
        for (int i = 0; i < board.size(); i++) {
            visited.push_back(vector<bool>(board[0].size(), false));
        }

        unordered_set<string> hash;
        string cur;

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                helper(board, i, j, cur, visited, root, hash);
            }
        }

        for (int i = 0; i < words.size(); i++) {
            if (hash.find(words[i]) != hash.end()) {
                existing_words.push_back(words[i]);
                hash.erase(words[i]);
            }
        }

        return existing_words;
    }
private:
    void add_word(const string& word) {
        TrieNode* node = root;
        for (int i = 0; i < word.length(); i++) {
            int index = word[i] - 'a';
            if (node->next[index] == NULL) {
                node->next[index] = new TrieNode();
            }
            node = node->next[index];
        }
        node->has_word = true;
    }

    void helper(const vector<vector<char> > &board, int x, int y, string& cur, vector<vector<bool>>& visited, TrieNode* node, unordered_set<string>& hash) {
        if (node == NULL) {
            return;
        }

        if (node->has_word) {
            if (hash.find(cur) == hash.end()) {
                hash.insert(cur);
            }
        }

        int n = board.size(), m = board[0].size();
        if (x < 0 || x >= n || y < 0 || y >= m || visited[x][y]) {
            return;
        }

        int index = board[x][y] - 'a';
        if (node->next[index] == NULL) {
            return;
        }

        const static int dx[4] = { -1, 1, 0, 0 };
        const static int dy[4] = { 0, 0, -1, 1 };

        cur.push_back(board[x][y]);
        visited[x][y] = true;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            helper(board, nx, ny, cur, visited, node->next[index], hash);
        }
        cur.pop_back();
        visited[x][y] = false;
    }
};
