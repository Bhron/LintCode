class Solution {
public:
    /**
     * @param n the integer to be reversed
     * @return the reversed integer
     */
    int reverseInteger(int n) {
        int reverse = 0;

        while (n != 0) {
            int tmp = reverse * 10 + n % 10;
            n /= 10;
            if (tmp / 10 != reverse) {
                return 0;
            }
            reverse = tmp;
        }

        return reverse;
    }
};
