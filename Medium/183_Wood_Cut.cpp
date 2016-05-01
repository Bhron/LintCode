class Solution {
public:
    /**
     *@param L: Given n pieces of wood with length L[i]
     *@param k: An integer
     *return: The maximum length of the small pieces.
     */
    int woodCut(vector<int> L, int k) {
        int low = 1, high = 0;
        for (int i = 0; i < L.size(); i++) {
            if (L[i] > high) {
                high = L[i];
            }
        }

        while (low + 1 < high) {
            int mid = low + (high - low) / 2;
            if (pieces(L, mid) >= k) {
                low = mid;
            } else {
                high = mid;
            }
        }

        if (pieces(L, high) >= k) {
            return high;
        }
        if (pieces(L, low) >= k) {
            return low;
        }
        return 0;
    }
private:
    int pieces(const vector<int>& L, int length) {
        int counter = 0;
        for (int i = 0; i < L.size(); i++) {
            counter += L[i] / length;
        }
        return counter;
    }
};
