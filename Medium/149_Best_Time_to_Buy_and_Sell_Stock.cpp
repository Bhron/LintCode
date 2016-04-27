class Solution {
public:
    /**
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(vector<int> &prices) {
        if (prices.empty()) {
            return 0;
        }

        int min_price = INT_MAX, profit = 0;
        for (int i = 0; i < prices.size(); i++) {
            if (prices[i] < min_price) {
                min_price = prices[i];
            }
            profit = max(profit, prices[i] - min_price);
        }

        return profit;
    }
};
