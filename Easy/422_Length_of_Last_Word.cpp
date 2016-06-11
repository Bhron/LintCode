class Solution {
public:
    /**
     * @param s A string
     * @return the length of last word
     */
    int lengthOfLastWord(string& s) {
        int i = s.length() - 1;
        while (i >= 0 && s[i] == ' ') {
            i--;
        }

        if (i < 0) {
            return 0;
        }

        int lastWordLength = 0;
        while (i >= 0 && s[i] != ' ') {
            lastWordLength++;
            i--;
        }

        return lastWordLength;
    }
};
