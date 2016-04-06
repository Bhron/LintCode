class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return an integer
     */
    int longestConsecutive(vector<int> &num) {
        if (num.empty()) {
            return 0;
        }

        unordered_map<int, bool> hash;
        for (int i = 0; i < num.size(); i++) {
            hash[num[i]] = true;
        }

        int max_len = 1;
        for (int i = 0; i < num.size(); i++) {
            int val = num[i];
            if (hash.find(val) == hash.end()) {
                continue;
            }

            int len = 0;
            while (hash.find(val) != hash.end()) {
                len++;
                hash.erase(val);
                val++;
            }
            val = num[i] - 1;
            while (hash.find(val) != hash.end()) {
                len++;
                hash.erase(val);
                val--;
            }

            max_len = max(len, max_len);
        }

        return max_len;
    }
};
