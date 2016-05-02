/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

// BFS
class Solution {
    /**
     * @param root: The root of binary tree.
     * @return: Level order a list of lists of integer
     */
public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        vector<vector<int> > values;

        if (root == NULL) {
            return values;
        }

        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty()) {
            vector<int> level_values;

            for(int i = 0, level_size = q.size(); i < level_size; i++) {
                TreeNode *node = q.front();
                q.pop();

                level_values.push_back(node->val);

                if (node->left != NULL) {
                    q.push(node->left);
                }
                if (node->right != NULL) {
                    q.push(node->right);
                }
            }

            values.push_back(level_values);
        }

        return values;
    }
};

// DFS
class Solution {
    /**
     * @param root: The root of binary tree.
     * @return: Level order a list of lists of integer
     */
public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        vector<vector<int> > values;

        if (root == NULL) {
            return values;
        }

        int cur_level = 0;
        while (true) {
            vector<int> level_values;

            dfs(root, level_values, 0, cur_level);
            if (level_values.empty()) {
                break;
            }

            values.push_back(level_values);
            cur_level++;
        }

        return values;
    }
private:
    void dfs(TreeNode *root, vector<int>& level_values, int cur_level, int max_level) {
        if (root == NULL) {
            return;
        }

        if (cur_level == max_level) {
            level_values.push_back(root->val);
            return;
        }

        dfs(root->left, level_values, cur_level + 1, max_level);
        dfs(root->right, level_values, cur_level + 1, max_level);
    }
};
