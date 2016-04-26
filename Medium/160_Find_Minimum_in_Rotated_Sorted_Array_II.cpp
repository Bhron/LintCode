class Solution {
public:
    /**
     * @param num: the rotated sorted array
     * @return: the minimum number in the array
     */
    int findMin(vector<int> &num) {
        int min;

        min = num[0];
        for (int i = 1; i < num.size(); i++) {
            if (num[i] < min) {
                min = num[i];
            }
        }

        return min;
    }
};
