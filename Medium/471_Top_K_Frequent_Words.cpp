class Solution {
public:
    /**
     * @param words an array of string
     * @param k an integer
     * @return an array of string
     */
    vector<string> topKFrequentWords(vector<string>& words, int k) {
        vector<string> frequent_words;

        if (words.empty() || k <= 0) {
            return frequent_words;
        }

        unordered_map<string, int> hash;
        for (int i = 0; i < words.size(); i++) {
            if (hash.find(words[i]) != hash.end()) {
                hash[words[i]] += 1;
            } else {
                hash[words[i]] = 1;
            }
        }

        // Min Heap
        priority_queue<Pair, std::vector<Pair>, Compare> pq;
        for (auto it = hash.begin(); it != hash.end(); it++) {
            string word = it->first;
            int count = it->second;

            if (pq.size() < k) {
                pq.push(Pair(word, count));
            } else {
                Pair p = pq.top();
                if (count > p.count || count == p.count && word < p.word) {
                    pq.pop();
                    pq.push(Pair(word, count));
                }
            }
        }

        while (!pq.empty()) {
            frequent_words.push_back(pq.top().word);
            pq.pop();
        }

        // Reverse
        int len = frequent_words.size();
        for (int i = 0; i < len / 2; i++) {
            swap(frequent_words[i], frequent_words[len - 1 - i]);
        }

        return frequent_words;
    }
private:
    class Pair {
    public:
        string word;
        int count;

        Pair(string word, int count) {
            this->word = word;
            this->count = count;
        }
    };

    // Min Heap
    class Compare {
    public:
        bool operator() (const Pair& left, const Pair& right) {
            if (left.count != right.count) {
                return left.count > right.count;
            }
            return left.word < right.word;
        }
    };
};
