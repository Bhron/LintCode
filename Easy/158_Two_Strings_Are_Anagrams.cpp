// Hash Table
class Solution {
public:
    /**
     * @param s: The first string
     * @param b: The second string
     * @return true or false
     */
    bool anagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }

        unordered_map<char, int> hash;

        for (int i = 0; i < s.length(); i++) {
            if (hash.find(s[i]) == hash.end()) {
                hash[s[i]] = 1;
            } else {
                hash[s[i]]++;
            }
        }

        for (int i = 0; i < t.length(); i++) {
            if (hash.find(t[i]) == hash.end()) {
                return false;
            } else {
                hash[t[i]]--;
            }
        }

        for (int i = 0; i < s.length(); i++) {
            if (hash[s[i]] != 0) {
                return false;
            }
        }

        return true;
    }
};

// Sort
class Solution {
public:
    /**
     * @param s: The first string
     * @param b: The second string
     * @return true or false
     */
    bool anagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        return s == t;
    }
};
