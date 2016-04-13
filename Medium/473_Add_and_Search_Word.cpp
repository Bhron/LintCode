class WordDictionary {
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
    WordDictionary() {
        root = new TrieNode();
    }

    // Adds a word into the data structure.
    void addWord(string word) {
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

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return search_helper(word, 0, root);
    }
private:
    bool search_helper(const string& word, int pos, TrieNode* node) {
        if (node == NULL) {
            return false;
        }

        if (pos == word.length()) {
            return node->has_word;
        }

        if (word[pos] == '.') {
            bool found = false;
            for (int i = 0; i < 26; i++) {
                if (search_helper(word, pos + 1, node->next[i])) {
                    return true;
                }
            }
            return false;
        } else {
            int index = word[pos] - 'a';
            return search_helper(word, pos + 1, node->next[index]);
        }
    }
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");
