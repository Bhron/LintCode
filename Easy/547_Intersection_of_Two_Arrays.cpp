// Hash Table
class Solution {
public:
    /**
     * @param nums1 an integer array
     * @param nums2 an integer array
     * @return an integer array
     */
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> intersections;

        if (nums1.empty() || nums2.empty()) {
            return intersections;
        }

        unordered_set<int> hash;
        for (int i = 0; i < nums1.size(); i++) {
            hash.insert(nums1[i]);
        }

        unordered_set<int> unique_nums;
        for (int i = 0; i < nums2.size(); i++) {
            if (hash.find(nums2[i]) != hash.end()) {
                unique_nums.insert(nums2[i]);
            }
        }

        for (const auto& num: unique_nums) {
            intersections.push_back(num);
        }

        return intersections;
    }
};
