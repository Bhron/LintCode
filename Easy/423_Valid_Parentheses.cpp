class Solution {
public:
    /**
     * @param s A string
     * @return whether the string is a valid parentheses
     */
    bool isValidParentheses(string& s) {
        if (s.empty()) {
            return true;
        }

        stack<char> parentheses;

        for (int i = 0; i < s.length(); i++) {
            char c = s[i];
            switch (c) {
                case '(':
                case '[':
                case '{':
                    parentheses.push(c);
                    break;
                case ')':
                    if (parentheses.empty() || parentheses.top() != '(') {
                        return false;
                    } else {
                        parentheses.pop();
                    }
                    break;
                case ']':
                    if (parentheses.empty() || parentheses.top() != '[') {
                        return false;
                    } else {
                        parentheses.pop();
                    }
                    break;
                case '}':
                    if (parentheses.empty() || parentheses.top() != '{') {
                        return false;
                    } else {
                        parentheses.pop();
                    }
                    break;
            }
        }

        return parentheses.empty();
    }
};
