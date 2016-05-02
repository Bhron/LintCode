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

class Solution {
    /**
     * @param root : The root of binary tree.
     * @return : buttom-up level order a list of lists of integer
     */
public:
    vector<vector<int>> levelOrderBottom(TreeNode *root) {
        vector<vector<int> > values;

        if (root == NULL) {
            return values;
        }

        queue<TreeNode *> q;
        q.push(root);
        int cur_level_node_num = 1;

        while (cur_level_node_num > 0) {
            vector<int> level_values;
            int next_level_node_num = 0;

            while (cur_level_node_num > 0) {
                TreeNode *node = q.front();
                q.pop();
                cur_level_node_num--;

                level_values.push_back(node->val);
                if (node->left != NULL) {
                    q.push(node->left);
                    next_level_node_num++;
                }
                if (node->right != NULL) {
                    q.push(node->right);
                    next_level_node_num++;
                }
            }

            values.insert(values.begin(), level_values);
            cur_level_node_num = next_level_node_num;
        }

        return values;
    }
};

class Solution {
    /**
     * @param root : The root of binary tree.
     * @return : buttom-up level order a list of lists of integer
     */
public:
    vector<vector<int>> levelOrderBottom(TreeNode *root) {
        vector<vector<int> > values;

        if (root == NULL) {
            return values;
        }

        queue<TreeNode *> q;
        q.push(root);
        int cur_level_node_num = 1;

        while (cur_level_node_num > 0) {
            vector<int> level_values;
            int next_level_node_num = 0;

            while (cur_level_node_num > 0) {
                TreeNode *node = q.front();
                q.pop();
                cur_level_node_num--;

                level_values.push_back(node->val);
                if (node->left != NULL) {
                    q.push(node->left);
                    next_level_node_num++;
                }
                if (node->right != NULL) {
                    q.push(node->right);
                    next_level_node_num++;
                }
            }

            values.insert(values.begin(), level_values);
            cur_level_node_num = next_level_node_num;
        }

        return values;
    }
};
