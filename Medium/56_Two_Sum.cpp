class Solution {
public:
    /*
     * @param numbers : An array of Integer
     * @param target : target = numbers[index1] + numbers[index2]
     * @return : [index1+1, index2+1] (index1 < index2)
     */
    vector<int> twoSum(vector<int> &nums, int target) {
        vector<int> indexes;

        if (nums.empty()) {
            return indexes;
        }

        unordered_map<int, int> hash;

        for (int i = 0; i < nums.size(); i++) {
            if (hash.find(target - nums[i]) != hash.end()) {
                indexes.push_back(hash[target - nums[i]] + 1);
                indexes.push_back(i + 1);
                sort(indexes.begin(), indexes.end());
                return indexes;
            }
            hash[nums[i]] = i;
        }

        return indexes;
    }
};
