class Solution {
public:
    /**
     * @param a a number
     * @param b a number
     * @return the result
     */
    string addBinary(string& a, string& b) {
        int n = a.length();
        int m = b.length();

        string result;

        int i, j, carry;
        for (i = n - 1, j = m - 1, carry = 0; i >= 0 || j >= 0 || carry != 0; ) {
            int sum = 0;

            sum += carry;
            if (i >= 0) {
                sum += a[i--] - '0';
            }
            if (j >= 0) {
                sum += b[j--] - '0';
            }

            result.insert(result.begin(), sum % 2 + '0');

            carry = sum / 2;
        }

        return result;
    }
};
