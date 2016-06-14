class Solution {
public:
    /**
     * @param A: Given an integers array A
     * @return: A long long array B and B[i]= A[0] * ... * A[i-1] * A[i+1] * ... * A[n-1]
     */
    vector<long long> productExcludeItself(vector<int> &nums) {
        vector<long long> B;

        if (nums.empty()) {
            return B;
        }

        vector<long long> leftProduct(nums.size(), 0);
        long long product = 1;
        for (int i = 0; i < nums.size(); i++) {
            leftProduct[i] = product;
            product *= nums[i];
        }

        vector<long long> rightProduct(nums.size(), 0);
        product = 1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            rightProduct[i] = product;
            product *= nums[i];
        }

        for (int i = 0; i < nums.size(); i++) {
            product = leftProduct[i] * rightProduct[i];
            B.push_back(product);
        }

        return B;
    }
};
