class Solution {
public:
    /**
     * @param str: a string
     * @param offset: an integer
     * @return: nothing
     */
    void rotateString(string &str, int offset){
        if (str.empty()) {
            return;
        }

        int length = str.length();
        offset = offset % length;

        reverse(str, 0, length - offset - 1);
        reverse(str, length - offset, length - 1);
        reverse(str, 0, length - 1);
    }
private:
    void reverse(string& str, int start, int end) {
        while (start < end) {
            char tmp = str[start];
            str[start] = str[end];
            str[end] = tmp;

            start++;
            end--;
        }
    }
};
