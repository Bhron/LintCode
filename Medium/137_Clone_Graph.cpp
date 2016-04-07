/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    /**
     * @param node: A undirected graph node
     * @return: A undirected graph node
     */
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (node == NULL) {
            return NULL;
        }

        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> map;
        map[node] = new UndirectedGraphNode(node->label);

        vector<UndirectedGraphNode*> nodes;
        nodes.push_back(node);

        int start = 0;
        while (start < nodes.size()) {
            UndirectedGraphNode* cur = nodes[start++];

            for (int i = 0; i < cur->neighbors.size(); i++) {
                UndirectedGraphNode* neighbor = cur->neighbors[i];
                if (map.find(neighbor) == map.end()) {
                    map[neighbor] = new UndirectedGraphNode(neighbor->label);
                    nodes.push_back(neighbor);
                }
            }
        }

        for (int i = 0; i < nodes.size(); i++) {
            UndirectedGraphNode* new_node = map[nodes[i]];
            for (int j = 0; j < nodes[i]->neighbors.size(); j++) {
                new_node->neighbors.push_back(map[nodes[i]->neighbors[j]]);
            }
        }

        return map[node];
    }
};
