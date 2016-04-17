// Loop & Check
class Solution {
public:
    /**
     * @param num: an integer
     * @return: an integer, the number of ones in num
     */
    int countOnes(int num) {
        int counter = 0;

        for (int i = 0; i < 32; i++) {
            counter += num & 0x1;
            num >>= 1;
        }

        return counter;
    }
};

// Bit Trick, O(m), m is the number of 1 bits
class Solution {
public:
    /**
     * @param num: an integer
     * @return: an integer, the number of ones in num
     */
    int countOnes(int num) {
        int counter = 0;

        while (num != 0) {
            counter++;
            num &= num - 1;
        }

        return counter;
    }
};
