class Solution {
public:
    /**
     * @param n an integer
     * @return true if this is a happy number or false
     */
    bool isHappy(int n) {
        if (n <= 0) {
            return false;
        }

        unordered_set<int> hash;

        while (n != 1) {
            hash.insert(n);

            int sum = 0;

            while (n != 0) {
                int digit = n % 10;
                sum += digit * digit;
                n /= 10;
            }
            if (hash.find(sum) != hash.end()) {
                return false;
            }

            n = sum;
        }

        return true;
    }
};
