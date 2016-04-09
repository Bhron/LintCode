/**
 * Definition for Directed graph.
 * struct DirectedGraphNode {
 *     int label;
 *     vector<DirectedGraphNode *> neighbors;
 *     DirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    /**
     * @param nodes a array of directed graph node
     * @return a connected set of a directed graph
     */
    vector<vector<int>> connectedSet2(vector<DirectedGraphNode*>& nodes) {
        vector<vector<int>> components;

        if (nodes.empty()) {
            return components;
        }

        for (int i = 0; i < nodes.size(); i++) {
            parents[nodes[i]->label] = nodes[i]->label;
        }

        for (int i = 0; i < nodes.size(); i++) {
            DirectedGraphNode* node = nodes[i];
            for (int j = 0; j < node->neighbors.size(); j++) {
                DirectedGraphNode* neighbor = node->neighbors[j];
                merge(node->label, neighbor->label);
            }
        }

        unordered_map<int, int> hash;

        int counter = 0;
        for (int i = 0; i < nodes.size(); i++) {
            int parent = find(nodes[i]->label);
            if (hash.find(parent) == hash.end()) {
                hash[parent] = counter++;
            }

            if (components.size() < counter) {
                components.push_back(vector<int>());
            }
            (components[hash[parent]]).push_back(nodes[i]->label);
        }

        parents.clear();

        return components;
    }
private:
    unordered_map<int, int> parents;

    int find(int x) {
        int parent = x;
        while (parent != parents[parent]) {
            parent = parents[parent];
        }

        int root = parent, tmp;
        parent = x;
        while (parent != parents[parent]) {
            tmp = parents[parent];
            parents[parent] = root;
            parent = tmp;
        }

        return root;
    }

    void merge(int a, int b) {
        int parent_a = find(a);
        int parent_b = find(b);

        if (parent_a != parent_b) {
            parents[parent_b] = parent_a; // parents[parent_a] = parent_b
        }
    }
};
