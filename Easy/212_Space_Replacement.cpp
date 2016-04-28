class Solution {
public:
    /**
     * @param string: An array of Char
     * @param length: The true length of the string
     * @return: The true length of new string
     */
    int replaceBlank(char string[], int length) {
        if (length == 0) {
            return 0;
        }

        int new_length = length;
        for (int i = 0; i < length; i++) {
            if (string[i] == ' ') {
                new_length += 2;
            }
        }

        for (int i = new_length - 1, j = length - 1; j >= 0; j--) {
            if (string[j] != ' ') {
                string[i--] = string[j];
            } else {
                string[i--] = '0';
                string[i--] = '2';
                string[i--] = '%';
            }
        }

        return new_length;
    }
};
