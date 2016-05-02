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

// Non-Recursion
class Solution {
public:
    /**
     * @param root: The root of binary tree.
     * @return: Preorder in vector which contains node values.
     */
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> values;

        if (root == NULL) {
            return values;
        }

        stack<TreeNode *> s;
        s.push(root);

        while (!s.empty()) {
            TreeNode *node = s.top();
            s.pop();

            values.push_back(node->val);

            if (node->right != NULL) {
                s.push(node->right);
            }
            if (node->left != NULL) {
                s.push(node->left);
            }
        }

        return values;
    }
};

// Recursion
class Solution {
public:
    /**
     * @param root: The root of binary tree.
     * @return: Preorder in vector which contains node values.
     */
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> values;

        if (root == NULL) {
            return values;
        }

        preorder_traversal_helper(values, root);

        return values;
    }
private:
    void preorder_traversal_helper(vector<int> &values, TreeNode *root) {
        if (root == NULL) {
            return;
        }

        values.push_back(root->val);
        preorder_traversal_helper(values, root->left);
        preorder_traversal_helper(values, root->right);
    }
};

// Divide & Conquer
class Solution {
public:
    /**
     * @param root: The root of binary tree.
     * @return: Preorder in vector which contains node values.
     */
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> values;

        if (root == NULL) {
            return values;
        }

        values.push_back(root->val);
        vector<int> left_values = preorderTraversal(root->left);
        vector<int> right_values = preorderTraversal(root->right);

        values.insert(values.end(), left_values.begin(), left_values.end());
        values.insert(values.end(), right_values.begin(), right_values.end());

        return values;
    }
};
