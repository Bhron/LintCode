/**
 * Definition for Undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */

// BFS
class Solution {
public:
    /**
     * @param nodes a array of Undirected graph node
     * @return a connected set of a Undirected graph
     */
    vector<vector<int>> connectedSet(vector<UndirectedGraphNode*>& nodes) {
        vector<vector<int>> components;

        if (nodes.empty()) {
            return components;
        }

        unordered_set<UndirectedGraphNode*> visited;

        for (int i = 0; i < nodes.size(); i++) {
            if (visited.find(nodes[i]) == visited.end()) {
                helper(nodes[i], visited, components);
            }
        }

        return components;
    }
private:
    void helper(UndirectedGraphNode* node, unordered_set<UndirectedGraphNode*>& visited, vector<vector<int>>& components) {
        vector<int> component;

        queue<UndirectedGraphNode*> q;
        q.push(node);

        visited.insert(node);

        while (!q.empty()) {
            UndirectedGraphNode* node = q.front();
            q.pop();

            component.push_back(node->label);

            for (int i = 0; i < node->neighbors.size(); i++) {
                UndirectedGraphNode* neighbor = node->neighbors[i];
                if (visited.find(neighbor) == visited.end()) {
                    q.push(neighbor);
                    visited.insert(neighbor);
                }
            }
        }

        sort(component.begin(), component.end());

        components.push_back(component);
    }
};

// Union Find
class Solution {
public:
    /**
     * @param nodes a array of Undirected graph node
     * @return a connected set of a Undirected graph
     */
    vector<vector<int>> connectedSet(vector<UndirectedGraphNode*>& nodes) {
        vector<vector<int>> components;

        if (nodes.empty()) {
            return components;
        }

        for (int i = 0; i < nodes.size(); i++) {
            parents[nodes[i]->label] = nodes[i]->label;
        }

        for (int i = 0; i < nodes.size(); i++) {
            UndirectedGraphNode* node = nodes[i];
            for (int j = 0; j < node->neighbors.size(); j++) {
                UndirectedGraphNode* neighbor = node->neighbors[j];
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
            parents[parent_b] = parent_a;
        }
    }
};
