class Solution {
public:
    /**
     * @param A: A string includes Upper Case letters
     * @param B: A string includes Upper Case letter
     * @return:  if string A contains all of the characters in B return true
     *           else return false
     */
    bool compareStrings(string A, string B) {
        if (B.empty()) {
            return true;
        }
        if (A.empty()) {
            return false;
        }

        vector<int> alphabet(26, 0);

        for (int i = 0; i < A.length(); i++) {
            alphabet[A[i] - 'A']++;
        }

        for (int i = 0; i < B.length(); i++) {
            int index = B[i] - 'A';
            alphabet[index]--;
            if (alphabet[index] < 0) {
                return false;
            }
        }

        return true;
    }
};
