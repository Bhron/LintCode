class Solution {
public:
    /**
     * @param s a string
     * @return an integer
     */
    int minCut(string s) {
        if (s.empty()) {
            return 0;
        }

        int n = s.length();

        int F[n + 1];
        for (int i = 0; i <= n; i++) {
            F[i] = i - 1;
        }

        bool** is_palindrome = get_is_palindrome(s);

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                if (is_palindrome[j][i - 1]) {
                    F[i] = min(F[j] + 1, F[i]);
                }
            }
        }

        return F[n];
    }
private:
    bool** get_is_palindrome(string s) {
        int n = s.length();

        bool** is_palindrome = new bool*[n];
        for (int i = 0; i < n; i++) {
            is_palindrome[i] = new bool[n];
        }

        for (int i = 0; i < n; i++) {
            is_palindrome[i][i] = true;
        }
        for (int i = 0; i < n - 1; i++) {
            is_palindrome[i][i + 1] = s[i] == s[i + 1];
        }

        for (int length = 2; length < n; length++) {
            for (int i = 0; i + length < n; i++) {
                is_palindrome[i][i + length] = is_palindrome[i + 1][i + length - 1] && s[i] == s[i + length];
            }
        }

        return is_palindrome;
    }
};
