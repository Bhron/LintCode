class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: A list of integers includes the index of the first number
     *          and the index of the last number
     */
    vector<int> subarraySum(vector<int> nums){
        vector<int> indexes;

        if (nums.empty()) {
            return indexes;
        }

        unordered_map<int, int> hash;
        hash[0] = -1;

        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (hash.find(sum) != hash.end()) {
                indexes.push_back(hash[sum] + 1);
                indexes.push_back(i);
                return indexes;
            }
            hash[sum] = i;
        }

        return indexes;
    }
};
