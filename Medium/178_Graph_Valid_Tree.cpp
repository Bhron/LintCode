class Solution {
public:
    /**
     * @param n an integer
     * @param edges a list of undirected edges
     * @return true if it's a valid tree, or false
     */
    bool validTree(int n, vector<vector<int>>& edges) {
        if (n - 1 != edges.size()) {
            return false;
        }

        parents.clear();
        for (int i = 0; i < n; i++) {
            parents[i] = i;
        }

        for (int i = 0; i < edges.size(); i++) {
            int parent_p = find(edges[i][0]);
            int parent_c = find(edges[i][1]);

            if (parent_p == parent_c) {
                return false;
            }
            merge(edges[i][0], edges[i][1]);
        }

        return true;
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
