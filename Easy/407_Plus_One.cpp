class Solution {
public:
    /**
     * @param digits a number represented as an array of digits
     * @return the result
     */
    vector<int> plusOne(vector<int>& digits) {
        if (digits.empty()) {
            return digits;
        }

        int carry = 1;
        for (int i = digits.size() - 1; i >= 0 && carry != 0; i--) {
            int sum = digits[i] + carry;
            digits[i] = sum % 10;
            carry = sum / 10;
        }

        if (carry != 0) {
            digits.insert(digits.begin(), 1);
        }

        return digits;
    }
};
