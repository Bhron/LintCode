class Solution {
public:
    /**
     * @param s: A string s
     * @param dict: A dictionary of words dict
     */
    bool wordBreak(string s, unordered_set<string> &dict) {
        if (s.empty() || dict.empty()) {
            if (s.empty() && dict.empty()) {
                return true;
            }
            if (s.empty() && dict.find("") != dict.end()) {
                return true;
            }
            return false;
        }

        int n = s.length();
        bool F[n + 1];

        int max_word_length = get_max_word_length(dict);
        F[0] = true;

        for (int i = 1; i <= n; i++) {
            F[i] = false;
            for (int last_word_length = 1; last_word_length <= i && last_word_length <= max_word_length; last_word_length++) {
                if (!F[i - last_word_length]) {
                    continue;
                }
                string word = s.substr(i - last_word_length, last_word_length);
                if (dict.find(word) != dict.end()) {
                    F[i] = true;
                    break;
                }
            }
        }

        return F[n];
    }
private:
    int get_max_word_length(unordered_set<string> &dict) {
        int max_length = 0;

        for (auto it = dict.begin(); it != dict.end(); it++) {
            if ((*it).length() > max_length) {
                max_length = (*it).length();
            }
        }

        return max_length;
    }
};
