class Solution {
public:
    /**
     * @param str: A string
     * @return An integer
     */
    int atoi(string str) {
        if (str.empty()) {
            return 0;
        }

        int i;
        for (i = 0; i < str.length() && str[i] == ' '; i++) {
            ;
        }

        if (i == str.length()) {
            return 0;
        }

        int sign = 1;
        if (str[i] == '-') {
            sign = -1;
            i++;
        } else if (str[i] == '+') {
            i++;
        }

        if (i == str.length()) {
            return 0;
        }

        long result = 0;
        for ( ; i < str.length() && isdigit(str[i]); i++) {
            result = result * 10 + (str[i] - '0');
            if (result > INT_MAX) {
                break;
            }
        }
        result *= sign;

        if (result > INT_MAX) {
            return INT_MAX;
        } else if (result < INT_MIN) {
            return INT_MIN;
        }
        return result;
    }
};
