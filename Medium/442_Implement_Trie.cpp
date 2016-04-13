// Use array to store links
/**
 * Your Trie object will be instantiated and called as such:
 * Trie trie;
 * trie.insert("lintcode");
 * trie.search("lint"); will return false
 * trie.startsWith("lint"); will return true
 */
class TrieNode {
public:
    bool has_word;
    TrieNode* next[26];

    // Initialize your data structure here.
    TrieNode() {
        has_word = false;
        for (int i = 0; i < 26; i++) {
            next[i] = NULL;
        }
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
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

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode* node = root;
        for (int i = 0; i < word.length(); i++) {
            int index = word[i] - 'a';
            if (node->next[index] == NULL) {
                return false;
            }
            node = node->next[index];
        }
        return node->has_word;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for (int i = 0; i < prefix.length(); i++) {
            int index = prefix[i] - 'a';
            if (node->next[index] == NULL) {
                return false;
            }
            node = node->next[index];
        }
        return true;
    }

private:
    TrieNode* root;
};

// Use hash map to store links
/**
 * Your Trie object will be instantiated and called as such:
 * Trie trie;
 * trie.insert("lintcode");
 * trie.search("lint"); will return false
 * trie.startsWith("lint"); will return true
 */
class TrieNode {
public:
    bool has_word;
    unordered_map<char, TrieNode*> next;

    // Initialize your data structure here.
    TrieNode() {
        has_word = false;
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode* node = root;
        for (int i = 0; i < word.length(); i++) {
            char c = word[i];
            if (node->next.find(c) == node->next.end()) {
                node->next[c] = new TrieNode();
            }
            node = node->next[c];
        }
        node->has_word = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode* node = root;
        for (int i = 0; i < word.length(); i++) {
            char c = word[i];
            if (node->next.find(c) == node->next.end()) {
                return false;
            }
            node = node->next[c];
        }
        return node->has_word;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for (int i = 0; i < prefix.length(); i++) {
            char c = prefix[i];
            if (node->next.find(c) == node->next.end()) {
                return false;
            }
            node = node->next[c];
        }
        return true;
    }

private:
    TrieNode* root;
};
