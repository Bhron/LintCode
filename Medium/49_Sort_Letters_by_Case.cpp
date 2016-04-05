class Solution {
public:
    /**
     * @param chars: The letters array you should sort.
     */
    void sortLetters(string &letters) {
        int i = 0, j = letters.length() - 1;
        while (i < j) {
            while (i < j && islower(letters[i])) {
                i++;
            }
            while (i < j && isupper(letters[j])) {
                j--;
            }
            if (i < j) {
                int tmp = letters[i];
                letters[i] = letters[j];
                letters[j] = tmp;
                i++;
                j--;
            }
        }
    }
};
