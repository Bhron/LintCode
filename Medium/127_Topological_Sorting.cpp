/**
 * Definition for Directed graph.
 * struct DirectedGraphNode {
 *     int label;
 *     vector<DirectedGraphNode *> neighbors;
 *     DirectedGraphNode(int x) : label(x) {};
 * };
 */

// BFS
class Solution {
public:
    /**
     * @param graph: A list of Directed graph node
     * @return: Any topological order for the given graph.
     */
    vector<DirectedGraphNode*> topSort(vector<DirectedGraphNode*> graph) {
        vector<DirectedGraphNode*> result;

        if (graph.empty()) {
            return result;
        }

        unordered_map<DirectedGraphNode*, int> map;
        for (int i = 0; i < graph.size(); i++) {
            DirectedGraphNode* node = graph[i];

            for (int j = 0; j < node->neighbors.size(); j++) {
                DirectedGraphNode* neighbor = node->neighbors[j];

                if (map.find(neighbor) != map.end()) {
                    map[neighbor]++;
                } else {
                    map[neighbor] = 1;
                }
            }
        }

        queue<DirectedGraphNode*> q;
        for (int i = 0; i < graph.size(); i++) {
            DirectedGraphNode* node = graph[i];

            if (map.find(node) == map.end()) {
                q.push(node);
            }
        }

        while (!q.empty()) {
            DirectedGraphNode* node = q.front();
            q.pop();
            result.push_back(node);

            for (int i = 0; i < node->neighbors.size(); i++) {
                DirectedGraphNode* neighbor = node->neighbors[i];

                map[neighbor]--;
                if (map[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        return result;
    }
};

// DFS
class Solution {
public:
    /**
     * @param graph: A list of Directed graph node
     * @return: Any topological order for the given graph.
     */
    vector<DirectedGraphNode*> topSort(vector<DirectedGraphNode*> graph) {
        vector<DirectedGraphNode*> result;

        if (graph.empty()) {
            return result;
        }

        unordered_map<DirectedGraphNode*, int> map;
        for (int i = 0; i < graph.size(); i++) {
            DirectedGraphNode* node = graph[i];

            for (int j = 0; j < node->neighbors.size(); j++) {
                DirectedGraphNode* neighbor = node->neighbors[j];

                if (map.find(neighbor) != map.end()) {
                    map[neighbor]++;
                } else {
                    map[neighbor] = 1;
                }
            }
        }

        for (int i = 0; i < graph.size(); i++) {
            DirectedGraphNode* node = graph[i];

            if (map.find(node) == map.end()) {
                helper(graph, result, map, node);
            }
        }

        return result;
    }
private:
    void helper(vector<DirectedGraphNode*>& graph, vector<DirectedGraphNode*>& result, unordered_map<DirectedGraphNode*, int>& map, DirectedGraphNode* node) {
        result.push_back(node);

        map[node]--;

        for (int i = 0; i < node->neighbors.size(); i++) {
            DirectedGraphNode* neighbor = node->neighbors[i];

            map[neighbor]--;
            if (map[neighbor] == 0) {
                helper(graph, result, map, neighbor);
            }
        }
    }
};
