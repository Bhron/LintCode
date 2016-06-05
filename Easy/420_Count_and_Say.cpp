class Solution {
public:
    /**
     * @param n the nth
     * @return the nth sequence
     */
    string countAndSay(int n) {
        string seq;

        if (n <= 0) {
            return seq;
        } else if (n == 1) {
            return "1";
        }

        seq = "1";
        n--;
        while (n-- > 0) {
            string tmp;

            int i = 0;
            while (i < seq.length()) {
                char c = seq[i];

                int j = i + 1;
                for ( ; j < seq.length() && seq[j] == c; j++) {
                    ;
                }

                tmp += to_string(j - i) + c;

                i = j;
            }

            seq = tmp;
        }

        return seq;
    }
};
