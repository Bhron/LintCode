// BFS
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
     * @param graph: A list of Directed graph node
     * @param s: the starting Directed graph node
     * @param t: the terminal Directed graph node
     * @return: a boolean value
     */
    bool hasRoute(vector<DirectedGraphNode*> graph,
                  DirectedGraphNode* s, DirectedGraphNode* t) {
        if (graph.empty() || s == NULL || t == NULL) {
            return false;
        }

        unordered_set<DirectedGraphNode*> visited;
        queue<DirectedGraphNode*> q;

        q.push(s);
        while (!q.empty()) {
            DirectedGraphNode* node = q.front();
            q.pop();

            if (node == t) {
                return true;
            }

            visited.insert(node);

            for (int i = 0; i < node->neighbors.size(); i++) {
                DirectedGraphNode* neighbor = node->neighbors[i];
                if (visited.find(neighbor) == visited.end()) {
                    q.push(neighbor);
                    visited.insert(neighbor);
                }
            }
        }

        return false;
    }
};

// DFS
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
     * @param graph: A list of Directed graph node
     * @param s: the starting Directed graph node
     * @param t: the terminal Directed graph node
     * @return: a boolean value
     */
    bool hasRoute(vector<DirectedGraphNode*> graph,
                  DirectedGraphNode* s, DirectedGraphNode* t) {
        if (graph.empty() || s == NULL || t == NULL) {
            return false;
        }

        unordered_set<DirectedGraphNode*> visited;
        return dfs(graph, s, t, visited);
    }

    bool dfs(vector<DirectedGraphNode*>& graph, DirectedGraphNode* node, DirectedGraphNode* t, unordered_set<DirectedGraphNode*>& visited) {
        if (node == t) {
            return true;
        }

        visited.insert(node);

        for (int i = 0; i < node->neighbors.size(); i++) {
            DirectedGraphNode* neighbor = node->neighbors[i];
            if (visited.find(neighbor) == visited.end()) {
                bool found = dfs(graph, neighbor, t, visited);
                if (found) {
                    return true;
                }
            }
        }

        return false;
    }
};
