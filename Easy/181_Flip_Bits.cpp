class Solution {
public:
    /**
     *@param a, b: Two integer
     *return: An integer
     */
    int bitSwapRequired(int a, int b) {
        int counter = 0;

        for (int i = 0; i < 32; i++) {
            int a_bit = a & 0x1;
            int b_bit = b & 0x1;
            counter += a_bit ^ b_bit;

            a >>= 1;
            b >>= 1;
        }

        return counter;
    }
};

class Solution {
public:
    /**
     *@param a, b: Two integer
     *return: An integer
     */
    int bitSwapRequired(int a, int b) {
        int counter = 0;

        for (unsigned int c = a ^ b; c != 0; c >>= 1) {
            counter += c & 0x1;
        }

        return counter;
    }
};
