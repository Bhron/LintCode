class Solution {
public:
    /**
     * @param strs: A list of strings
     * @return: A list of strings
     */
    vector<string> anagrams(vector<string> &strs) {
        vector<string> result;

        if (strs.empty()) {
            return result;
        }

        unordered_map<string, int> hash;
        for (int i = 0; i < strs.size(); i++) {
            string anagram = get_anagram(strs[i]);
            if (hash.find(anagram) == hash.end()) {
                hash[anagram] = 1;
            } else {
                hash[anagram]++;
            }
        }

        for (int i = 0; i < strs.size(); i++) {
            string anagram = get_anagram(strs[i]);
            if (hash[anagram] > 1) {
                result.push_back(strs[i]);
            }
        }

        return result;
    }
private:
    string get_anagram(const string& str) {
        if (str.empty()) {
            return "";
        }

        vector<int> alphabet(26, 0);
        for (int i = 0; i < str.length(); i++) {
            alphabet[str[i] - 'a']++;
        }

        string anagram;
        for (int i = 0; i < alphabet.size(); i++) {
            if (alphabet[i] > 0) {
                anagram += string(alphabet[i], 'a' + i);
            }
        }

        return anagram;
    }
};
