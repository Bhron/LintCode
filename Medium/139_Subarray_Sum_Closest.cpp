class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: A list of integers includes the index of the first number
     *          and the index of the last number
     */
    vector<int> subarraySumClosest(vector<int> nums){
        vector<int> indexes(2, -1);

        if (nums.empty()) {
            return indexes;
        }

        vector<Pair> pairs;
        pairs.push_back(Pair(0, -1));

        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            pairs.push_back(Pair(sum, i));
        }

        sort(pairs.begin(), pairs.end());

        int closest_sum = INT_MAX;
        bool found = false;
        for (int i = 0; i < pairs.size() - 1; i++) {
            int sum = abs(pairs[i + 1].sum - pairs[i].sum);
            if (!found || sum < closest_sum) {
                closest_sum = sum;
                indexes[0] = min(pairs[i].index, pairs[i + 1].index) + 1;
                indexes[1] = max(pairs[i].index, pairs[i + 1].index);
                found = true;
            }
        }

        return indexes;
    }
private:
    class Pair {
    public:
        int sum;
        int index;

        Pair(int sum, int index) {
            this->sum = sum;
            this->index = index;
        }

        bool operator < (const Pair &p) const {
            return sum < p.sum || sum == p.sum && index < p.index;
        }
    };
};
