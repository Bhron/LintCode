class Solution {
public:
    /**
     * @param s: A string
     * @return: A list of lists of string
     */
    vector<vector<string>> partition(string s) {
        vector<vector<string>> partitions;

        if (s.empty()) {
            return partitions;
        }

        vector<string> cur;

        helper(s, 0, cur, partitions);

        return partitions;
    }
private:
    void helper(const string& s, int pos, vector<string>& cur, vector<vector<string>>& partitions) {
        if (pos == s.length()) {
            partitions.push_back(vector<string>(cur));
            return;
        }

        for (int i = pos; i < s.length(); i++) {
            string sub_str = s.substr(pos, i - pos + 1);

            if (!is_palindrome(sub_str)) {
                continue;
            }

            cur.push_back(sub_str);
            helper(s, i + 1, cur, partitions);
            cur.pop_back();
        }
    }

    bool is_palindrome(const string& s) {
        int len = s.length();

        for (int i = 0; i < len / 2; i++) {
            if (s[i] != s[len - 1 - i]) {
                return false;
            }
        }

        return true;
    }
};
