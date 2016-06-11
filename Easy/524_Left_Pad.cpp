class StringUtils {
public:
    /**
     * @param originalStr the string we want to append to
     * @param size the target length of the string
     * @param padChar the character to pad to the left side of the string
     * @return a string
     */
    static string leftPad(string& originalStr, int size, char padChar=' ') {
        if (size > originalStr.length()) {
            originalStr.insert(0, string(size - originalStr.length(), padChar));
        }
        return originalStr;
    }
};
