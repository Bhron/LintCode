class Solution {
public:
    /**
      * @param start, a string
      * @param end, a string
      * @param dict, a set of string
      * @return an integer
      */
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        if (dict.empty()) {
            return 0;
        }

        unordered_set<string> hash;
        queue<string> q;

        hash.insert(start);
        q.push(start);

        dict.insert(end);

        int length = 1;
        while (!q.empty()) {
            length++;

            int size = q.size();
            for (int i = 0; i < size; i++) {
                string word = q.front();
                q.pop();

                vector<string> transformations = get_transformations(word, dict);
                for (int j = 0; j < transformations.size(); j++) {
                    if (transformations[j] == end) {
                        return length;
                    }

                    if (hash.find(transformations[j]) == hash.end()) {
                        q.push(transformations[j]);
                        hash.insert(transformations[j]);
                    }
                }
            }
        }

        return 0;
    }
private:
    vector<string> get_transformations(string word, const unordered_set<string> &dict) {
        vector<string> transformations;

        for (char c = 'a'; c <= 'z'; c++) {
            for (int i = 0; i < word.length(); i++) {
                if (word[i] == c) {
                    continue;
                }

                string transformation(word);
                transformation[i] = c;

                if (dict.find(transformation) != dict.end()) {
                    transformations.push_back(transformation);
                }
            }
        }

        return transformations;
    }
};
