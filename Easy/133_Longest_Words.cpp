// Two Pass
class Solution {
public:
    /**
     * @param dictionary: a vector of strings
     * @return: a vector of strings
     */
    vector<string> longestWords(vector<string> &dictionary) {
        vector<string> words;

        if (dictionary.empty()) {
            return words;
        }

        int max_len = 0;
        for (int i = 0; i < dictionary.size(); i++) {
            if (dictionary[i].length() > max_len) {
                max_len = dictionary[i].length();
            }
        }

        for (int i = 0; i < dictionary.size(); i++) {
            if (dictionary[i].length() == max_len) {
                words.push_back(dictionary[i]);
            }
        }

        return words;
    }
};

// One Pass
class Solution {
public:
    /**
     * @param dictionary: a vector of strings
     * @return: a vector of strings
     */
    vector<string> longestWords(vector<string> &dictionary) {
        vector<string> words;

        if (dictionary.empty()) {
            return words;
        }

        int max_len = 0;
        for (int i = 0; i < dictionary.size(); i++) {
            string word = dictionary[i];
            if (word.length() >= max_len) {
                if (word.length() > max_len) {
                    max_len = word.length();
                    words.clear();
                }
                words.push_back(word);
            }
        }

        return words;
    }
};
