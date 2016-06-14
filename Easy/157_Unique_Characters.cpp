class Solution {
public:
    /**
     * @param str: a string
     * @return: a boolean
     */
    bool isUnique(string &str) {
        if (str.empty()) {
            return true;
        }

        unordered_map<char, int> hash;
        for (int i = 0; i < str.length(); i++) {
            if (hash[str[i]] == 0) {
                hash[str[i]] = 1;
            } else {
                return false;
            }
        }

        return true;
    }
};
