class Solution {
public:
    /**
     *@param A: A list of integers
     *@param elem: An integer
     *@return: The new length after remove
     */
    int removeElement(vector<int> &A, int elem) {
        if (A.empty()) {
            return 0;
        }

        int i = 0, j = 0;
        while (i < A.size()) {
            if (A[i] != elem) {
                A[j++] = A[i];
            }
            i++;
        }

        return j;
    }
};
