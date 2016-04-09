class Solution {
public:
    /**
      * @param start, a string
      * @param end, a string
      * @param dict, a set of string
      * @return a list of lists of string
      */
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        vector<vector<string>> sequences;

        if (dict.empty()) {
            return sequences;
        }

        dict.insert(end);
        bfs(start, end, dict);

        vector<string> sequence;
        dfs(start, dict, sequences, sequence, end);

        distance.clear();
        transformations_map.clear();

        return sequences;
    }
private:
    unordered_map<string, int> distance;
    unordered_map<string, vector<string>> transformations_map;

    void bfs(const string& start, const string& end, const unordered_set<string> &dict) {
        queue<string> q;
        q.push(start);

        distance[start] = 1;

        for (auto it = dict.begin(); it != dict.end(); it++) {
            transformations_map[*it] = vector<string>();
        }

        int length = 1;
        bool reach_end = false;
        while (!q.empty() && !reach_end) {
            length++;

            int size = q.size();
            for (int i = 0; i < size; i++) {
                string word = q.front();
                q.pop();

                vector<string> transformations = get_transformations(word, dict);
                for (int j = 0; j < transformations.size(); j++) {
                    string next = transformations[j];

                    (transformations_map[next]).push_back(word);

                    if (distance.find(next) == distance.end()) {
                        distance[next] = length;
                        q.push(next);
                    }

                    if (next == end) {
                        reach_end = true;
                    }
                }
            }
        }
    }

    void dfs(const string& start, const unordered_set<string> &dict, vector<vector<string>>& sequences, vector<string>& sequence, const string word) {

        sequence.push_back(word);

        if (word == start) {
            generate_sequence(sequences, sequence);
        } else {
            vector<string> transformations = transformations_map[word];
            for (int i = 0; i < transformations.size(); i++) {
                string next = transformations[i];

                if (distance.find(next) != distance.end() && distance[next] + 1 == distance[word]) {
                    dfs(start, dict, sequences, sequence, next);
                }
            }
        }

        sequence.pop_back();
    }

    vector<string> get_transformations(const string& word, const unordered_set<string> &dict) {
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

    void generate_sequence(vector<vector<string>>& sequences, vector<string>& sequence) {
        vector<string> result;

        for (int i = sequence.size() - 1; i >= 0; i--) {
            result.push_back(sequence[i]);
        }

        sequences.push_back(result);
    }
};
