class Solution {
    /**
     * param A : an integer ratated sorted array and duplicates are allowed
     * param target :  an integer to be search
     * return : a boolean
     */
public:
    bool search(vector<int> &A, int target) {
        if (A.empty()) {
            return false;
        }

        bool found = false;

        for (int i = 0; i < A.size(); i++) {
            if (A[i] == target) {
                return true;
            }
        }

        return found;
    }
};
