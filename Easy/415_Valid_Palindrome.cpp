class Solution {
public:
    /**
     * @param s A string
     * @return Whether the string is a valid palindrome
     */
    bool isPalindrome(string& s) {
        if (s.empty()) {
            return true;
        }

        int start = 0, end = s.length() - 1;
        while (start < end) {
            if (!isalnum(s[start])) {
                start++;
            } else if (!isalnum(s[end])) {
                end--;
            } else if (tolower(s[start]) != tolower(s[end])) {
                return false;
            } else {
                start++;
                end--;
            }
        }

        return true;
    }
};
