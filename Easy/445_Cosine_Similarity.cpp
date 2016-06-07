class Solution {
public:
    /**
     * @param A: An integer array.
     * @param B: An integer array.
     * @return: Cosine similarity.
     */
    double cosineSimilarity(vector<int> A, vector<int> B) {
        double similarity = 2.0;

        if (A.empty() || B.empty()) {
            return similarity;
        }

        int A_B_product_sum = 0, A_square_sum = 0, B_square_sum = 0;
        for (int i = 0; i < A.size(); i++) {
            A_B_product_sum += A[i] * B[i];
            A_square_sum += A[i] * A[i];
            B_square_sum += B[i] * B[i];
        }

        if (A_square_sum == 0 || B_square_sum == 0) {
            return similarity;
        }

        similarity = ((double)A_B_product_sum) / (sqrt(A_square_sum) * sqrt(B_square_sum));

        return similarity;
    }
};
