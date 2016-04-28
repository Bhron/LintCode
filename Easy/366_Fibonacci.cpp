class Solution{
public:
    /**
     * @param n: an integer
     * @return an integer f(n)
     */
    int fibonacci(int n) {
        int first = 0, second = 1;
        for (int i = 1; i < n; i++) {
            first = first + second;

            int tmp = second;
            second = first;
            first = tmp;
        }

        return first;
    }
};
