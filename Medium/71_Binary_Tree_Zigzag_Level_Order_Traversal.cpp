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
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> values;

        if (root == NULL) {
            return values;
        }

        queue<TreeNode*> q;
        q.push(root);

        bool is_left_to_right = true;
        while (!q.empty()) {
            vector<int> level_values;
            int level_size = q.size();
            stack<int> s;

            for (int i = 0; i < level_size; i++) {
                TreeNode* node = q.front();
                q.pop();

                if (node->left != NULL) {
                    q.push(node->left);
                }
                if (node->right != NULL) {
                    q.push(node->right);
                }

                if (is_left_to_right) {
                    level_values.push_back(node->val);
                } else {
                    s.push(node->val);
                }
            }

            if (!is_left_to_right) {
                while (!s.empty()) {
                    level_values.push_back(s.top());
                    s.pop();
                }
            }

            values.push_back(level_values);
            is_left_to_right = !is_left_to_right;
        }

        return values;
    }
};

class Solution {
    /**
     * @param root: The root of binary tree.
     * @return: A list of lists of integer include
     *          the zigzag level order traversal of its nodes' values
     */
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int> > zigzag_values;

        if (root == NULL) {
            return zigzag_values;
        }

        stack<TreeNode *> *cur_level = new stack<TreeNode *>();
        stack<TreeNode *> *next_level = new stack<TreeNode *>();
        cur_level->push(root);

        bool zigzag_order_left_right = true;
        while (!cur_level->empty()) {
            vector<int> level_values;

            while (!cur_level->empty()) {
                TreeNode *node = cur_level->top();
                cur_level->pop();

                level_values.push_back(node->val);

                if (zigzag_order_left_right) {
                    if (node->left != NULL) {
                        next_level->push(node->left);
                    }
                    if (node->right != NULL) {
                        next_level->push(node->right);
                    }
                } else {
                    if (node->right != NULL) {
                        next_level->push(node->right);
                    }
                    if (node->left != NULL) {
                        next_level->push(node->left);
                    }
                }
            }

            zigzag_values.push_back(level_values);

            stack<TreeNode *> *tmp = cur_level;
            cur_level = next_level;
            next_level = tmp;

            zigzag_order_left_right = !zigzag_order_left_right;
        }

        return zigzag_values;
    }
};
